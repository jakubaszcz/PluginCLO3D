#ifndef CLO_REST_API_H_
#define CLO_REST_API_H_

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
}

namespace CLOAPI
{
	/*
	// At the moment, we support for GET, POST and POST with multipart/form-data method only.
	@param url : the full URL for REST API call
	@param headerNameAndValueList : pair list of input HTTP request header parameters
	e.g.		Host: www.clo-set.com,
			Authorization: Basic a3lsZS5~~~~~
			X-User-Provider: 0
	@param progressBarText : text for the progress bar

	@return string = HTTP Response header + "\r\n\r\n" + HTTP Response body
	e.g. 	HTTP/1.1 200 OK
			Content-Type: application/json; charset=utf-8
			Content-Length: 290
			...
			Via: 1.1 0859cbbec76cd864e788367b8aaae34b.cloudfront.net (CloudFront)
			X-Amz-Cf-Id: CiBbTByCkXRrFM6rbpMN9v3hZtVUkyzsJki-02HjpKMabs6yKZtcqw==

			{"result_code":1,"result_message":"SUCCESS"}
	*/

	// HTTP GET Method
	/*
	@param url : e.g. https://api.clo3d.com/customers?version=2.5.9999.299999&userid=clo
	@param headerNameAndValueList : pair list of input HTTP request header parameters
	@param progressBarText : text for the progress bar
	@return string = HTTP Response header + "\r\n\r\n" + HTTP Response body
	*/
	MV_CLO_SCENE_API string CallRESTGet(const string& url, const vector<pair<string, string>>& headerNameAndValueList, const string& progressBarText);

	// HTTP POST Method
	/*
	e.g. 	POST / HTTP/1.1
			Host: foo.com
			Content-Type: application/x-www-form-urlencoded
			Content-Length: 13

			body

	// In the above example, "body" corresponds to this string parameter.
	// If you want to send json type parameters to the server, you can put a jason string in this parameter string.
	@param url : the full URL for REST API call
	@param postField HTTP Post Body parameter
		e.g. "{"parameter1":20,"parameter2":100,"date":"2017-12-13T00:00:00"}"
	@param headerNameAndValueList : pair list of input HTTP request header parameters
	@param progressBarText : text for the progress bar
	@return string = HTTP Response header + "\r\n\r\n" + HTTP Response body
	*/
	MV_CLO_SCENE_API string CallRESTPost(const string& url, string *postField, const vector<pair<string, string>>& headerNameAndValueList, const string& progressBarText);

	/*
	@param url : the full URL for REST API call
	@param postField HTTP Post Body parameter
	@param sizeInByte The size of postField in bytes
	@param headerNameAndValueList : pair list of input HTTP request header parameters
	@param progressBarText : text for the progress bar
	@return string = HTTP Response header + "\r\n\r\n" + HTTP Response body
	 */
	MV_CLO_SCENE_API string CallRESTPost2(const string& url, unsigned char *postField, unsigned int& sizeInByte, const vector<pair<string, string>>& headerNameAndValueList, const string& progressBarText);

	// HTTP POST with multipart/form-data Method
	/*
	e.g.	POST /test.html HTTP/1.1
			Host: example.org
			Content-Type: multipart/form-data;boundary="boundary"

			--boundary
			Content-Disposition: form-data; name="field1"

			value1
			--boundary
			Content-Disposition: form-data; name="field2"; filename="example.txt"

			value2

	@param url : the full URL for REST API call
	@param filePath : path of file to send via REST API
	@param headerNameAndValueList : pair list of input HTTP request header parameters
	@param progressBarText : text for the progress bar
	@return string = HTTP Response header + "\r\n\r\n" + HTTP Response body
	*/
	MV_CLO_SCENE_API string CallRESTPostWithMultipartFormData(const string& url, const string& filePath, const vector<pair<string, string>>& headerNameAndValueList, const string& progressBarText);

	// HTTP POST with multipart/form-data Method
	/*
	@param url : the full URL for REST API call
	@param filePathList : path list of files to send via REST API
	@param headerNameAndValueList : pair list of input HTTP request header parameters
	@param progressBarText : text for the progress bar
	@return string = HTTP Response header + "\r\n\r\n" + HTTP Response body
	*/
	MV_CLO_SCENE_API string CallRESTPostWithMultipartFormData(const string& url, const vector<string>& filePathList, const vector<pair<string, string>>& headerNameAndValueList, const string& progressBarText);
}

#endif //REST_API_H_
