﻿#ifndef CLO_LIBRARY_WINDOW_API_H_
#define CLO_LIBRARY_WINDOW_API_H_

#ifdef LIBRARYAPIIMPL_EXPORTS
#define MV_CLO_SCENE_API __declspec(dllexport)
#else
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
#endif

#include <string>
#include <iostream>


using namespace std;

namespace CLOAPI
{

typedef unsigned char CLO_BYTE;

enum CLO_FINDER_SORT
{
	NAME,
	DATE_TIME
};

class MV_CLO_SCENE_API LibraryWindowInterface
{
public:
	LibraryWindowInterface() {}
	virtual ~LibraryWindowInterface() {}

public:
	/*
	If the return value of this function is true, the UI is activated in the CLO Library.
	@return When implementing this dll, the return value should always be true.
	*/
	virtual bool EnableCustomUI()
	{
		return false;
	}

	/*	
	This function will be called either when CLO Library Window opens or when a user clicks a folder icon.
	It returns a item (file or folder) list under a folder. CLO will display the item list in its Library window.
	
	@param itemId The ID of the current folder. If itemId is "", it must return the item list of the root folder.
	@param pageNo Page number(default:1). pageNo will be given by user's scroll.
	@param pageSize The number of items to display in a page. 
	@param sort
	@param bAscending
	@param searchText
	@return The item list in json format. Developers should implement this function so that it returns the item list corresponding to "pageNo" and "pageSize".
	
		itemID : Unique id
		type : FOLDER or FILE
		name : Item name
		dateTime : dateTime in ISO 8601 format (https://en.wikipedia.org/wiki/ISO_8601#Coordinated_Universal_Time_(UTC)
		fileSize : file size in bytes		
	
		[
		{
		"itemID": "/Users/inoblaze/Documents/CLO Install",
		"type": "FOLDER",
		"name": "CLO Install",
		"dateTime": "2018-03-09T11:10:03"
		}
		,
		{
		"itemID": "/Users/inoblaze/Documents/FLANNEL SHIRT-A.Zprj",
		"type": "FILE",
		"name": "FLANNEL SHIRT-A.Zprj",
		"dateTime": "2017-08-25T16:21:41",
		"fileSize": 5703918
		}
		,
		{
		"itemID": "/Users/inoblaze/Documents/1920x1080.png",
		"type": "FILE",
		"name": "1920x1080.png",
		"dateTime": "2018-01-04T13:34:30",
		"fileSize": 1099570
		}
		,
		{
		"itemID": "/Users/inoblaze/Documents/9865.txt",
		"type": "FILE",
		"name": "9865.txt",
		"dateTime": "2018-08-31T15:28:32",
		"filesize": 9038
		}
		,
		{
		"itemID": "/Users/inoblaze/Documents/dressform.Zprj",
		"type": "FILE",
		"name": "dressform.Zprj",
		"dateTime": "2017-07-14T18:16:35",
		"fileSize": 3464539
		}
		]
	*/
	virtual string GetItemList(const string& itemId, unsigned int pageNo, unsigned int pageSize, CLO_FINDER_SORT sort, bool bAscending, const string& searchText)
	{
		return "";
	}
	
	/*
	
	*/
	virtual string GetSearchItemList(unsigned int pageNo, unsigned int pageSize, CLO_FINDER_SORT sort, bool bAscending, const string& searchText)
	{
		return "";
	}

	/*
	@param parentFolderID The ID of the parent folder. 
	@return If any exceptions happen, this function should return "false". If the parent folder is "root", it should return "" ad parentFolderID. 
	*/
	virtual bool GetParentFolderID(const string& itemId, string& parentFolderID)
	{
		return false;
	}

	/*
	This function is called when starting paging from CLO SW. 

	@param itemId The ID of a file item
	@param sizeInByte The size of returned thumbnail image data in bytes
	@return Thumbnail image data in byte array. The data should be given in PNG format.
	*/
	virtual CLO_BYTE* GetPNGThumbnail(const string& itemId, unsigned int& sizeInByte)
	{
		return NULL;
	}

	/*
	will be supported in v5.1 or above
	*/
	virtual string GetMetaData(const string& itemId)
	{
		return "";
	}

	/*
	will be supported in v5.1 or above
	*/
	virtual CLO_BYTE* GetPreviewImage(const string& itemId, unsigned int& sizeInByte)
	{
		return NULL;
	}

	/*
	This function is called when a user double-clicks/drag-drops a thumbnail icon of a file item.
	~~~~

	@param itemId The ID of a file item
	@param sizeInByte The size of returned file data in bytes
	@return file data in byte array
	*/
	virtual CLO_BYTE* GetFile(const string& itemId, unsigned int& sizeInByte)
	{
		return NULL;
	}
};

}

#endif //LIBRARY_WINDOW_API_H_

