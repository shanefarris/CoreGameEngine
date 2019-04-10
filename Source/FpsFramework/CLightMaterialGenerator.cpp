#if 0
#include "CLightMaterialGenerator.h"
#include "CMiniLight.h"

using namespace Core::Effects;

class LightMaterialGeneratorHLSL: public CMaterialGenerator::Impl
{
public:
	LightMaterialGeneratorHLSL(const String& BaseName): mBaseName(BaseName) { }

	typedef CMaterialGenerator::Perm Perm;

	virtual GpuProgramPtr generateVertexShader(Perm permutation)
	{
		if(permutation & CMiniLight::MI_QUAD)
		{
			return HighLevelGpuProgramManager::getSingleton().getByName("DeferredShading/post/vs");
		}
		else
		{
			return HighLevelGpuProgramManager::getSingleton().getByName("DeferredShading/post/LightMaterial_vs");
		}
	}
	virtual GpuProgramPtr generateFragmentShader(Perm permutation)
	{
		bool isAttenuated = permutation & CMiniLight::MI_ATTENUATED > 0 ? true : false;
		bool isSpecular = permutation & CMiniLight::MI_SPECULAR > 0 ? true : false;
		// bool isShadowed = perm&4;

		/// Create name
		String name=mBaseName+StringConverter::toString(permutation)+"_ps";
		/// Create shader
		std::stringstream shader;
		shader <<
		"sampler Tex0: register(s0);\n"
		"sampler Tex1: register(s1);\n"
		"float4x4 worldView;\n"
		// Attributes of light
		"float4 lightDiffuseColor;\n"
		"float4 lightSpecularColor;\n"
		"float4 lightFalloff;\n"
		"float4 main(float2 texCoord: TEXCOORD0, float3 projCoord: TEXCOORD1) : COLOR\n"
		"{\n"
		"    float4 a0 = tex2D(Tex0, texCoord); \n"// Attribute 0: Diffuse color+shininess
		"    float4 a1 = tex2D(Tex1, texCoord); \n"// Attribute 1: Normal+depth
		// Attributes
		"    float3 colour = a0.rgb;\n"
		"    float alpha = a0.a;"		// Specularity
		"    float distance = a1.w;"	// Distance from viewer (w)
		"    float3 normal = a1.xyz;\n"
		// Calculate position of texel in view space
		"    float3 position = projCoord*distance;\n"
		// Extract position in view space from worldView matrix
		"	 float3 lightPos = float3(worldView[0][3],worldView[1][3],worldView[2][3]);\n"
		// Calculate light direction and distance
		"    float3 lightVec = lightPos - position;\n"
		"    float len_sq = dot(lightVec, lightVec);\n"
		"    float len = sqrt(len_sq);\n"
		"    float3 lightDir = lightVec/len;\n"
		/// Calculate attenuation
		"    float attenuation = saturate( 1-(len / lightFalloff.x ));\n"
		"    attenuation = (attenuation * attenuation * lightFalloff.w) + (lightFalloff.z * attenuation) ;\n"
		/// Calculate diffuse colour
		"    float3 light_diffuse = max(0,dot(lightDir, normal)) * lightDiffuseColor;\n"
		/// Calculate specular component
		"    float3 viewDir = -normalize(position);\n"
		"    float3 h = normalize(viewDir + lightDir);\n"
		"    float3 light_specular = pow(dot(normal, h),32) * lightSpecularColor;\n"
		// Accumulate total lighting for this fragment
		"    float3 total_light_contrib;\n"
		"    total_light_contrib = light_diffuse;\n"; 
		if(isSpecular)
		{
			/// Calculate specular contribution
			shader << 
			"	 total_light_contrib += alpha * light_specular;\n";
		}
		if(isAttenuated)
		{
			shader <<
			"    return float4(total_light_contrib*colour*attenuation, 0);\n";
		}
		else
		{
			shader <<
			"    return float4(total_light_contrib*colour, 0);\n";
		}
		shader <<
		"}\n";
		
		/// Create shader object
		HighLevelGpuProgramPtr program = HighLevelGpuProgramManager::getSingleton().createProgram(
			name, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			"hlsl", GPT_FRAGMENT_PROGRAM);
		program->setSource(shader.str());
		program->setParameter("target","ps_2_0");
		program->setParameter("entry_point","main");
		/// Set up default parameters
		GpuProgramParametersSharedPtr params = program->getDefaultParameters();
		params->setNamedAutoConstant("worldView", GpuProgramParameters::ACT_WORLDVIEW_MATRIX, 0);
		params->setNamedAutoConstant("lightDiffuseColor", GpuProgramParameters::ACT_CUSTOM, 1);
		if(isSpecular)
			params->setNamedAutoConstant("lightSpecularColor", GpuProgramParameters::ACT_CUSTOM, 2);
		if(isAttenuated)
			params->setNamedAutoConstant("lightFalloff", GpuProgramParameters::ACT_CUSTOM, 3);

		return HighLevelGpuProgramManager::getSingleton().getByName(program->getName());
	}
	virtual MaterialPtr generateTemplateMaterial(Perm permutation)
	{
		if(permutation & CMiniLight::MI_QUAD)
		{
			return MaterialManager::getSingleton().getByName("DeferredShading/LightMaterialQuad");
		}
		else
		{
			return MaterialManager::getSingleton().getByName("DeferredShading/LightMaterial");
		}
	}

protected:
	String mBaseName;

};

CLightMaterialGenerator::CLightMaterialGenerator(const String &Language)
{
	bitNames.push_back("Quad");		  // MI_QUAD
	bitNames.push_back("Attenuated"); // MI_ATTENUATED
	bitNames.push_back("Specular");   // MI_SPECULAR

	vsMask = 0x00000001;
	fsMask = 0x00000006;
	matMask = 0x00000001;
	
	materialBaseName = "DeferredShading/LightMaterial/";
	mImpl = new LightMaterialGeneratorHLSL("DeferredShading/LightMaterial/");
}

#endif