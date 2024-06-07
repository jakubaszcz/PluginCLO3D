#ifndef CLO_UTILITY_API_H_
#define CLO_UTILITY_API_H_

#ifdef CLO_SCENE_LIB_DYNAMIC_EXPORTS

#if defined(__APPLE__)
#define MV_CLO_SCENE_API
#else
#define MV_CLO_SCENE_API __declspec(dllexport)
#endif

#elif CLO_SCENE_LIB_STATIC
#define MV_CLO_SCENE_API

#else
#if defined(__APPLE__)
#define MV_CLO_SCENE_API 
#else
#define MV_CLO_SCENE_API __declspec(dllimport)
#endif

#endif

#include <vector>

using namespace std;

namespace Marvelous
{
	
}

namespace CLOAPI
{
	/*
	@return Get the temporary folder path to store temporary files used when exporting to server
	*/
	MV_CLO_SCENE_API string GetCLOTemporaryFolderPath();
	
	/*
	Display a message box to show input string on CLO. This can be used for debugging. 
	*/
	MV_CLO_SCENE_API void ShowMessageBox(string str);

	/*
	@return The current project name. When you opening "test.zprj" file at last, then the project name is given as "test"
	*/
	MV_CLO_SCENE_API string GetProjectName();

	/*
	@return Major version of SW. ex) 5 of 5.0.72
	*/
	MV_CLO_SCENE_API unsigned int GetMajorVersion();

	/*
	@return Minor version of SW. ex) 0 of 5.0.72
	*/
	MV_CLO_SCENE_API unsigned int GetMinorVersion();

	/*
	@return Patch version of SW. ex) 72 of 5.0.72
	*/
	MV_CLO_SCENE_API unsigned int GetPatchVersion();
}


#endif