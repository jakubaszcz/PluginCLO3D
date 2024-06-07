#ifndef CLO_EXPORT_API_H_
#define CLO_EXPORT_API_H_

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
	class View3DBase;
	class SceneGraph;
	class PatternEditor;
	class Library;

	enum EXPORTFILETYPE
	{
		EXPORT_OBJ_FILE,
		EXPORT_FBX_FILE,
		EXPORT_LXO_FILE
	};
	enum TEXTURE_SAVE_METHOD
	{
		RELATIVE_PATH,
		ABSOLUTE_PATH,
		SAVE_WITH_TEXTURE
	};

	enum WELD_TYPE
	{
		FULLY_UNWELDED = 0,
		DEFAULT_WELDED = 1, /// deprecated, but DO NOT REMOVE.
		FULLY_WELDED = 2,
		SELECTED_WELDED = 3
	};

	class MV_CLO_SCENE_API ImportExportOption
	{
	public:

		/////////////////////////
		// Export OBJ
		
		bool bExportGarment; /// if true, export garment meshes
		bool bExportAvatar; /// if true, export avatar meshes

		bool bSingleObject; /// true : OBJ single object, false : OBJ multiple object
		WELD_TYPE weldType; /// FULLY_UNWELDED : unweld, FULLY_WELDED : weld, SELECTED_WELDED : Weld selected patterns in workspace, DEFAULT_WELDED : Do not use!!!

		bool bUnifiedUVCoordinates; /// flag for Unified UV Coordinates
		bool bCreateUnifiedTexture; /// flag for Unified Texture option
		float unifiedTextureSize; /// the size of unified texture (pixels). Texture will be created in square. 
		float unifiedTextureFillSeam; /// Fill texture seam in millimeters(mm)

		bool bIncludeInnerShape; /// If true, export geometries of internal lines to ease the picking the internal lines in external modeling tools such as Maya and 3ds Max.

		float scale; /// how to scale the object created in CLO when exporting. The default unit of CLO is millimeters (mm).
		
		int axisX; /// the index of the axis which the X axis will be converted to. If you don't want axis conversion, set this value as "0"
		int axisY; /// the index of the axis which the Y axis will be converted to. If you don't want axis conversion, set this value as "1"
		int axisZ; /// the index of the axis which the Z axis will be converted to. If you don't want axis conversion, set this value as "2"
		bool bInvertX; /// invert the axis which the X axis will be converted to
		bool bInvertY; /// invert the axis which the Y axis will be converted to
		bool bInvertZ; /// invert the axis which the Z axis will be converted to

		bool bSaveInZipWithTextures; /// If true, export as a zipped file with textures. It will output a single zipped file(.zip), not separated files.
		bool bDiffuseColorCombined; /// if true, the texture will be exported after being combined with diffuse color	
		bool bExcludeAmbient; /// if true, exclude ambient map and color in MTL files.
		bool bOpacityMap; /// if true, generate an opacity map by extracting alpha channel from diffuse map
		bool bMetaData; /// export meta data

		// end of Export OBJ
		/////////////////////////
		
		/////////////////////////
		//	for FBX export only
		bool bAscii; /// fbx ascii or binary
		int  fbxSdkVersion; /// 0 : 2016, 1: 2014/2015, 2: 2013, 3 : 2012
		TEXTURE_SAVE_METHOD textureSaveMethod;

		/////////////////////////
		// for vertex cache only
		float timeScale; ///
		unsigned int fps; /// import/export vertex cache 

		/////////////////////////
		// for Alembic only
		float anim_step;
		bool bExportShutterSpeed;
		float shutter_low;
		float shutter_high;

		/////////////////////////
		// for ZBrush, Alembic only
		bool bIncludeAvatarShape;

		ImportExportOption()
		{
			bExportGarment = true;
			bExportAvatar = true;

			bSingleObject = false;
			weldType = FULLY_UNWELDED;

			bUnifiedUVCoordinates = false;
			bCreateUnifiedTexture = false;
			unifiedTextureSize = 2048.0f;
			unifiedTextureFillSeam = 1.0f;

			bIncludeInnerShape = false;

			scale = 1.0f;
			
			axisX = 0;
			axisY = 1;
			axisZ = 2;
			bInvertX = false;
			bInvertY = false;
			bInvertZ = false;

			bSaveInZipWithTextures = false;
			bDiffuseColorCombined = false;
			bExcludeAmbient = false;
			bOpacityMap = false;
			bMetaData = false;

			////
			bAscii = false;
			fbxSdkVersion = 0;
			textureSaveMethod = RELATIVE_PATH;

			anim_step = 1.0f;
			bExportShutterSpeed = false;
			shutter_low = 0.0f;
			shutter_high = 0.0f;
			bIncludeAvatarShape = true;

			//
			timeScale = 1.0f;
			fps = 30;
						
			
		}
		virtual ~ImportExportOption()
		{}
	};
}

namespace CLOAPI
{
	
	/*
	Export ZPac
	@return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API string ExportZPac();
	MV_CLO_SCENE_API string ExportZPac(const string& filePath);
		
	/*
	Export ZPrj
	@return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API string ExportZPrj();
	MV_CLO_SCENE_API string ExportZPrj(const string& filePath);

	/* 
	Export OBJ
	@param options If "options" is given, it exports OBJ according to options, not allowing user for selecting options in Export Dialog. 
	@return Output file paths. It outputs the file paths of an OBJ file and multiple MTL files for colorways. If the value "bSaveInZipWithTextures" in ImportExportOption is true, it outputs a file path of a zipped file. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API vector<string> ExportOBJ();
	MV_CLO_SCENE_API vector<string> ExportOBJ(const string& filePath);
	MV_CLO_SCENE_API vector<string> ExportOBJ(const Marvelous::ImportExportOption& options);
	MV_CLO_SCENE_API vector<string> ExportOBJ(const string& filePath, const Marvelous::ImportExportOption& options);

	/*
	Export DXF
	@return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API string ExportDXF();
	MV_CLO_SCENE_API string ExportDXF(const string& filePath);

	/*
	Export Tech Pack data in json file and associated image files. 
	@param filePath Should be given in "*.json" format
	@param bWithCaptureImage Set as true to save with associated images.
	*/
	MV_CLO_SCENE_API void ExportTechPack(const string& filePath, bool bWithCaptureImage);
		
	/*
	Export thumbnail of the current scene
	@return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API string ExportThumbnail3D();
	MV_CLO_SCENE_API string ExportThumbnail3D(const string& filePath);

	/*
	Export snapshot images. This function displays the same dialog as CLO so that users can configure the snapshots.
	If user turns on the option "Save Separate Images", then series of images will be saved with the name followed by the postfix "_01", "_02", ... 
	@return Return the list of the path of output files per colorway. The first item of each array is the file path of the unified image. If filePath parameter is not given, output files will be created in CLO temporary folder.				
	*/
	MV_CLO_SCENE_API vector< vector < string > > ExportSnapshot3D(const string& filePath);
	MV_CLO_SCENE_API vector< vector < string > > ExportSnapshot3D();
		
	/*
	Export Rendering Image.
	@param bRenderAllColorways If true, output the images for all colorways. Otherwise, it returns the images for the current colorway specified by CLO user.
	@param savedFilePathList Return the list of the path of output files per colorway. If filePath parameter is not given, output files will be created in CLO temporary folder.		
	@param colorwayIndex It starts with 0 index. It must not be over the total colorway size.
	*/		
	MV_CLO_SCENE_API vector< vector < string > > ExportRenderingImage(const string& filePath);
	MV_CLO_SCENE_API vector< vector < string > > ExportRenderingImage(const string& filePath, bool bRenderAllColorways);
	MV_CLO_SCENE_API vector< vector < string > > ExportRenderingImage(bool bRenderAllColorways);
	MV_CLO_SCENE_API vector < string > ExportSingleColorwayRenderingImage(const string& filePath, unsigned int colorwayIndex);
	MV_CLO_SCENE_API vector < string > ExportSingleColorwayRenderingImage(unsigned int colorwayIndex);

	/*
	Export garment information in json file. The information is the same as given in Garment Information Dialog in CLO (you can see this dialog by clicking File > Information > Garment menu in CLO)
	@return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API string ExportGarmentInformation();
	MV_CLO_SCENE_API string ExportGarmentInformation(const string& filePath);

	/*
	Export turntable video. This function requires XVid Mpeg-4 codec installed on user's computer.
	@return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API string ExportTurntableVideo();
	MV_CLO_SCENE_API string ExportTurntableVideo(const string& filePath);

	/*
	Export animation video. This function requires XVid Mpeg-4 codec installed on user's computer.
	@return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
	*/
	MV_CLO_SCENE_API string ExportAnimationVideo();
	MV_CLO_SCENE_API string ExportAnimationVideo(const string& filePath);
		
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/*
	@return total count of colorways
	*/
	MV_CLO_SCENE_API unsigned int GetColorwayCount();

	/*
	@return the current colorway index
	*/
	MV_CLO_SCENE_API unsigned int GetCurrentColorwayIndex();

	/*
	@return the list of name of all colorways
	*/
	MV_CLO_SCENE_API vector<string> GetColorwayNameList();

	/*
	@return total count of avatars
	*/
	MV_CLO_SCENE_API unsigned int GetAvatarCount();

	/*
	@return the list of name of all avatars
	*/
	MV_CLO_SCENE_API vector<string> GetAvatarNameList();

	/*
	@return the list of gender of all avatars. 0 : male, 1 : female, -1: unknown 
	*/
	MV_CLO_SCENE_API vector<int> GetAvatarGenderList();

	/*
	@return total count of sizes/gradings
	*/
	MV_CLO_SCENE_API unsigned int GetSizeCount();

	/*
	@return the current index of size/grading
	*/
	MV_CLO_SCENE_API unsigned int GetCurrentSizeIndex();

	/*
	@return the list of name of all sizes/gradings
	*/
	MV_CLO_SCENE_API vector<string> GetSizeNameList();

	

	
}


#endif
