/* This project relies on the recognise bytes form of the alpr cloud api
and works through the following steps
1.	Image is read and coverted to binary format
2.	Image is then piped through ostringstream and converted to string
3.	The additional methods outside of the main code convert this string to base64
4.	This base64 encoded string is then sent to the cloud api

USE CTRL + F5 TO RUN THE PROJECT SO YOU CAN SEE THE CONSOLE OUTPUT

API DETAILS
web: http://doc.openalpr.com/api/cloudapi.html#/default

BASE64_encode from: (further reading)
https://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp
*/

#include "alpr.h"
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <string>

static inline bool is_base64(unsigned char c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

static const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

//using namespace web::http;                  // Common HTTP functionality
//using namespace web::http::client;          // HTTP client features
using namespace std;

std::string base64_encode(unsigned char const* buf, unsigned int bufLen) {
	std::string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (bufLen--) {
		char_array_3[i++] = *(buf++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i <4); i++)
				ret += base64_chars[char_array_4[i]];
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while ((i++ < 3))
			ret += '=';
	}

	return ret;
}

vector<string> aplr(string path, wstring countryCode)
{
	string image_path = path;	//"D:\\us-4.jpg";
	wstring country_code = L"eu";

	// Read Image
	std::ifstream image(image_path, std::ios::in | std::ios::binary);
	std::ostringstream oss;
	oss << image.rdbuf();
	std::string s(oss.str());

	// Convert to base64 format using two functions above
	std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());

	wstring baseUrl = L"https://api.openalpr.com/v2/";
	//web::http::client::http_client httpClient(baseUrl);
	web::http::uri_builder builder(baseUrl);

	// Now build your URL based on the service you wish to use
	builder.append_path(U("recognize_bytes"));
	builder.append_query(U("secret_key"), U("sk_DEMODEMODEMODEMODEMODEMO"));
	builder.append_query(U("recognize_vehicle"), U("1"));
	builder.append_query(U("country"), country_code);
	builder.append_query(U("return_image"), U("0"));
	builder.append_query(U("topn"), U("10"));
	web::http::client::http_client client(builder.to_string());

	// Build the http request (POST)
	web::http::http_request req;
	req.set_method(web::http::methods::POST);
	req.headers().add(L"Content-Type", L"application/json");	// URL VERSION
	req.headers().add(L"Accept", L"application/json");
	req.set_body(encoded);

	web::json::value json_return;
	client.request(req).then([](const web::http::http_response& response) {
		return response.extract_json();
	})
		.then([&json_return](const pplx::task<web::json::value>& task) {
		try {
			json_return = task.get();
		}
		catch (const web::http::http_exception& e) {
			std::cout << "error " << e.what() << std::endl;
		}
	})
		.wait();
	
	// Declare container to pass back results
	vector<string> output;
	
	//IMAGE DETAILS (NUMBER EXAMPLE)
	int imH = (json_return.as_object().find(U("img_height"))->second).as_number().to_uint32();	// Defines as number and specifies uint32
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << imH))->str());			// Converts from number to string and stores in vect[0]
	int imW = (json_return.as_object().find(U("img_width"))->second).as_number().to_uint32();	// Defines as number and specifies uint32
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << imH))->str());			// Converts from number to string and stores in vect[1]
	
	// NUMBER PLATE (STRING EXAMPLE)
	auto results = (json_return.as_object().find(U("results"))->second).at(0);					// Finds results section
	wstring plate = results.as_object().find(U("plate"))->second.as_string();					// Converts plate results to wstring					
	string plateStr(plate.begin(), plate.end());												// Converst wstring to string
	output.push_back(plateStr);																	// Add to vector [2]
																						
	// VECHICLE REGION
	wstring v_region = results.as_object().find(U("region"))->second.as_string();
	string v_regionStr(v_region.begin(), v_region.end());
	output.push_back(v_regionStr);																//region --> [3]
	
	// PLATE REGION OF INTEREST
	auto coords = results.as_object().find(U("coordinates"))->second;
	int cY0 = coords.at(0).as_object().find(U("y"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cY0))->str());			//y0 --> [4]
	int cX0 = coords.at(0).as_object().find(U("x"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cX0))->str());			//x0 --> [5]
	int cY1 = coords.at(1).as_object().find(U("y"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cY1))->str());			//y1 --> [6]
	int cX1 = coords.at(1).as_object().find(U("x"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cX1))->str());			//x1 --> [7]
	int cY2 = coords.at(2).as_object().find(U("y"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cY2))->str());			//y2 --> [8]
	int cX2 = coords.at(2).as_object().find(U("x"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cX2))->str());			//x2 --> [9]
	int cY3 = coords.at(3).as_object().find(U("y"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cY3))->str());			//y3 --> [10]
	int cX3 = coords.at(3).as_object().find(U("x"))->second.as_number().to_uint32();
	output.push_back(static_cast<ostringstream*>(&(ostringstream() << cX3))->str());			//x3 --> [11]

	// CAR COLOUR
	auto vehicle_details = results.as_object().find(U("vehicle"))->second;	// Level 3
	wstring v_colour = vehicle_details.as_object().find(U("color"))->second.at(0).as_object().find(U("name"))->second.as_string();
	string v_colourStr(v_colour.begin(), v_colour.end());
	output.push_back(v_colourStr);																//colour --> [12]
	
	// CAR BODY TYPE
	wstring v_bType = vehicle_details.as_object().find(U("body_type"))->second.at(0).as_object().find(U("name"))->second.as_string();
	string v_bTypeStr(v_bType.begin(), v_bType.end());
	output.push_back(v_bTypeStr);																//Body type --> [13]

	// CAR MAKE
	wstring v_make = vehicle_details.as_object().find(U("make"))->second.at(0).as_object().find(U("name"))->second.as_string();
	string v_makeStr(v_make.begin(), v_make.end());
	output.push_back(v_makeStr);																//Body type --> [14]

	// OLDER STUFF FOR REFERENCE <-- WILL ONLY WORK IN CONSOLE SCRIPT
	//wcout << "CAR COLOUR CONFIDENCE: " << vehicle_details.as_object().find(U("color"))->second.at(0).as_object().find(U("confidence"))->second << endl;
	//wcout << "CAR MAKE: " << vehicle_details.as_object().find(U("make"))->second.at(0).as_object().find(U("name"))->second << endl;
	//wcout << "CAR MAKE CONFIDENCE: " << vehicle_details.as_object().find(U("make"))->second.at(0).as_object().find(U("confidence"))->second << endl;
	//wcout << "CAR BODY TYPE: " << vehicle_details.as_object().find(U("body_type"))->second.at(0).as_object().find(U("name"))->second << endl;
	//wcout << "CAR BODY TYPE CONFIDENCE: " << vehicle_details.as_object().find(U("body_type"))->second.at(0).as_object().find(U("confidence"))->second << endl;
	return output;
}

