cscript .\winPostBuild64.vbs

REM ********************** Config XML **********************************
copy ..\..\Media\config.xml ..\..\Bin\Debug
copy ..\..\Media\config.xml ..\..\Bin\Release
copy ..\..\Media\config.xml .\

copy ..\..\Media\config_orig.xml ..\..\Bin\Debug
copy ..\..\Media\config_orig.xml ..\..\Bin\Release
copy ..\..\Media\config_orig.xml .\

REM REM Output: $(SolutionDir)\Bin\$(ConfigurationName)
REM REM Intermediate: $(SolutionDir)\Obj\$(ProjectName)\$(ConfigurationName)
REM REM Link: $(Outdir)