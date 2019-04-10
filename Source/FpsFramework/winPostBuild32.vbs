Option Explicit

Dim fso 			' File object
Dim objFileCopy 	' Copy object
Dim oShell 			' Shell object to get environment variables
Dim LibDirDEB 		' Directory for CORE_64_DEB
Dim LibDirREL 		' Directory for CORE_64_REL

' Create our objects
Set fso = CreateObject("Scripting.FileSystemObject")
Set oShell = CreateObject( "WScript.Shell" )
LibDirDEB = oShell.ExpandEnvironmentStrings("%CORE_32_DEB%") & "\"
LibDirREL = oShell.ExpandEnvironmentStrings("%CORE_32_REL%") & "\"

' Create list of libraries to copy
Dim LibDebugList 
Dim LibReleaseList
LibDebugList = array("cg.dll", "OIS_d.dll", "caelum_d.dll", "Hydrax_d.dll", "MyGUIEngine_d.dll", "OgreMain_d.dll", _
					"OgreOverlay_d.dll", "OgrePaging_d.dll", "OgreRTShaderSystem_d.dll", "OgreTerrain_d.dll", _
					"Plugin_CgProgramManager_d.dll", "Plugin_OctreeSceneManager_d.dll", "Plugin_ParticleFX_d.dll", _
					"RenderSystem_Direct3D9_d.dll", "RakNetDebug.dll")

						'"NxCharacter.dll", "PhysXCooking.dll", "PhysXCore.dll", "PhysXDevice.dll", "PhysXLoader.dll", '"PhysXUpdateLoader.dll", "cudart32_30_9.dll", "OpenAL32.dll"
						', "Plugin_TheoraVideoSystem_d.dll"
						
LibReleaseList = array("cg.dll", "OIS.dll", "caelum.dll", "Hydrax.dll", "MyGUIEngine.dll", "OgreMain.dll", "OgreOverlay.dll", _
					"OgrePaging.dll", "OgreRTShaderSystem.dll", "OgreTerrain.dll", "Plugin_CgProgramManager.dll", _
					"Plugin_OctreeSceneManager.dll", "Plugin_ParticleFX.dll", "RenderSystem_Direct3D9.dll", "RakNet.dll")

						'"NxCharacter.dll", "PhysXCooking.dll", "PhysXCore.dll", "PhysXDevice.dll", "PhysXLoader.dll", '"PhysXUpdateLoader.dll", "cudart32_30_9.dll", "OpenAL32.dll"
						'"Plugin_TheoraVideoSystem.dll"

' Create to see if directories exisit, if not, create them
Sub CheckDirectories()
	If  Not fso.FolderExists("..\..\bin\") Then
		fso.CreateFolder ("..\..\bin\")
	End If
	
	If  Not fso.FolderExists("..\..\bin\Debug\") Then
		fso.CreateFolder ("..\..\bin\Debug\")
	End If
	
	If  Not fso.FolderExists("..\..\bin\Release\") Then
		fso.CreateFolder ("..\..\bin\Release\")
	End If
	
End Sub

Sub CopyLibraries(List, BaseDir)
	' Copy the libraries
	Dim Item
	For Each Item in List
		If Not fso.FileExists(BaseDir & Item) Then
			If Not fso.FileExists(LibDirDEB & Item) Then
				Wscript.Echo("***** " & LibDirDEB & Item & " ******** Does not exist")
			Else
				Wscript.Echo("Copying: " & BaseDir & Item)
				Set objFileCopy = fso.GetFile(LibDirDEB & Item)
				objFileCopy.Copy(BaseDir)
			End If
		End If
		
		If Not fso.FileExists(BaseDir & Item) Then
			If Not fso.FileExists(LibDirREL & Item) Then
				Wscript.Echo("***** " & LibDirREL & Item & " ******** Does not exist")
			Else
				Wscript.Echo("Copying: " & BaseDir & Item)
				Set objFileCopy = fso.GetFile(LibDirREL & Item)
				objFileCopy.Copy(BaseDir)
			End If
		End If
	Next
	
End Sub

CheckDirectories()

Wscript.Echo("*********** Copying to Debug *****************")
CopyLibraries LibDebugList, "..\..\bin\Debug\"

Wscript.Echo()
Wscript.Echo("*********** Copying to Relase ****************")
CopyLibraries LibReleaseList, "..\..\bin\Release\"

' Special logic here: Plugin_TheoraVideoSystem_d needs to be renamed to Plugin_TheoraVideoSystem
'if Not fso.FileExists("..\..\bin\Debug\Plugin_TheoraVideoSystem.dll") Then
'	fso.MoveFile "..\..\bin\Debug\Plugin_TheoraVideoSystem_d.dll", "..\..\bin\Debug\Plugin_TheoraVideoSystem.dll"
'End If


'Exit Script
WScript.Quit()
