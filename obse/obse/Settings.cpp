#include "Utilities.h"
#include "Settings.h"

bool InitializeSettings() {
	std::string	runtimePath = GetOblivionDirectory();
	//TODO create non existant INI
	if (!runtimePath.empty())
	{
		s_configPath = runtimePath;
		s_configPath += OBSEINI;

		_MESSAGE("config path = %s", s_configPath.c_str());
	}
	installCrashdump = GetPrivateProfileInt(INI_SECTION_RUNTIME, INI_RUNTIME_CRASHDUMP, 0, s_configPath.c_str());
	warningUDFRefVar = GetPrivateProfileInt(INI_SECTION_COMPILER, INI_COMPILER_WARNFUNCTPTR, 1, s_configPath.c_str());
	warningUnquotedString = GetPrivateProfileInt(INI_SECTION_COMPILER, INI_COMPILER_WARNUNQUOTEDSTRING, 1, s_configPath.c_str());
	FreeRef = GetPrivateProfileInt(INI_SECTION_RUNTIME, "DeallocateReferences", 0, s_configPath.c_str());

    return true;
}