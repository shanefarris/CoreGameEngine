#if 0
#include "CMaterialGenerator.h"

using namespace Core::Effects;

CMaterialGenerator::CMaterialGenerator(): vsMask(0), fsMask(0), matMask(0), mImpl(0)
{
}

CMaterialGenerator::~CMaterialGenerator()
{
	CORE_DELETE(mImpl);
}

const MaterialPtr &CMaterialGenerator::getMaterial(Perm permutation)
{
	/// Check input validity
	size_t totalBits = bitNames.size();
	size_t totalPerms = 1<<totalBits;
	assert(permutation < totalPerms);

	/// Check if material/shader permutation already was generated
	MaterialMap::iterator i = mMaterials.find(permutation);
	if(i != mMaterials.end())
	{
		return i->second;
	}
	else
	{
		/// Create it
		MaterialPtr templ = getTemplateMaterial(permutation & matMask);
		GpuProgramPtr vs = getVertexShader(permutation & vsMask);
		GpuProgramPtr fs = getFragmentShader(permutation & fsMask);
		
		/// Create material name
		String name=materialBaseName;
		for(size_t bit=0; bit<totalBits; ++bit)
			if(permutation & (1<<bit))
				name += bitNames[bit];

		std::cerr << name << " " << vs->getName() << " " << fs->getName() << std::endl;
		/// Create material from template, and set shaders
		MaterialPtr mat = templ->clone(name);
		Technique *tech = mat->getTechnique(0);
		Pass *pass = tech->getPass(0);
		pass->setFragmentProgram(fs->getName());
		pass->setVertexProgram(vs->getName());

		/// And store it
		mMaterials[permutation] = mat;
		return mMaterials[permutation];
	}
}

const GpuProgramPtr &CMaterialGenerator::getVertexShader(Perm permutation)
{
	ProgramMap::iterator i = mVs.find(permutation);
	if(i != mVs.end())
	{
		return i->second;
	}
	else
	{
		/// Create it
		mVs[permutation] = mImpl->generateVertexShader(permutation);
		return mVs[permutation];
	}
}

const GpuProgramPtr &CMaterialGenerator::getFragmentShader(Perm permutation)
{
	ProgramMap::iterator i = mFs.find(permutation);
	if(i != mFs.end())
	{
		return i->second;
	}
	else
	{
		/// Create it
		mFs[permutation] = mImpl->generateFragmentShader(permutation);
		return mFs[permutation];
	}
}

const MaterialPtr &CMaterialGenerator::getTemplateMaterial(Perm permutation)
{
	MaterialMap::iterator i = mTemplateMat.find(permutation);
	if(i != mTemplateMat.end())
	{
		return i->second;
	}
	else
	{
		/// Create it
		mTemplateMat[permutation] = mImpl->generateTemplateMaterial(permutation);
		return mTemplateMat[permutation];
	}
}

CMaterialGenerator::Impl::~Impl()
{
}


#endif