#ifndef CLO_WEB_API_H_
#define CLO_WEB_API_H_

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
	// At the moment, we support to open a web browser and to get the current URL for the web browser.
	*/

	
	// Open a web brower on CLO
	/*
	@param url : e.g. https://clo3d.com
	@param fp : call back function pointer for a void function with parameters (int, char**).
	@return bool = success or fail to open the web browser in CLO
	*/
	MV_CLO_SCENE_API bool OpenWebBrowserAPI(const string& url, void(*fp)(int argc, char** argv) = NULL);

	// Get the current URL from CLO web browser
	/*		
	@return string = current URL on the web browser in CLO
	*/
	MV_CLO_SCENE_API string GetCurrentURLOnWebkit();
	
}

#endif