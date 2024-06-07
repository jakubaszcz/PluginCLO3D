#ifndef CLO_IMPORT_API_H_
#define CLO_IMPORT_API_H_

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


using namespace std;

namespace CLOAPI
{
	
	/*
	Load File (zprj, zpac, avt, obj, fbx)
	*/
	MV_CLO_SCENE_API bool ImportFile(const string& filePath);
}


#endif