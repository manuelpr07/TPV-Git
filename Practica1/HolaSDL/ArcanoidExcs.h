//using namespace std;
//
//#include <string>
//#include <stdexcept>
//#include <sstream>
//#include <stdlib.h>
//
////ArkanoidError: hereda de logic error y sirve como superclase de todas las dem´as excepciones que definiremos.
////SDLError: Hereda de ArkanoidError y se utiliza para todos los errores relacionados con la inicializacion y uso de SDL
////FileNotFoundError: Hereda de ArkanoidError y se utiliza para todos los errores provocados al no encontrarse un fichero que el programa trata de abrir
////FileFormatError: Hereda de ArkanoidError y se utiliza para los errores provocados en la lectura de los ficheros de nivel y de partida guardada por formato incorrecto.
//
//class ArkanoidError : public logic_error {
//public:
//	ArkanoidError(const string& e) : logic_error(what() + e) {};
//	virtual const char* what()
//	{
//		return ("hay un error: ");
//	}
//};
//class SDLError : public ArkanoidError {
//protected:
//	int i;
//
//public:
//	SDLError(const string& e, int i) : ArkanoidError(what() + e) {};
//	const char* what()
//	{ 
//		// i = 0 si es sld_error y otra cosa si es img_error
//		if (i == 0)
//			SDL_GetError();
//		else IMG_GetError();
//	}
//	const char* SDL_GetError()
//	{
//		return ("Error en sdl: ");
//	}
//
//};
//class FileNotFoundError : public ArkanoidError {
//protected:
//	string file;
//
//public:
//	FileNotFoundError(const string& e) : ArkanoidError(what() + e), file(e) {};
//	const char* what()
//	{ 
//		return (char*)("archivo no encontrado: "/* + file.c_str()*/);
//	}
//};
//
//
//
//
//class VectorOutOfRangeExc : public out_of_range {
//protected:
//	int index;
//	int rangeIni;
//	int rangeEnd;
//public:
//	VectorOutOfRangeExc(const string& m, int i, int rIni, int rEnd) :
//		out_of_range(m + "Invalid access at pos. " + to_string(i) + ". Valid range is [" +  to_string(rIni) + "," + to_string(rEnd) + "]"), index(i), rangeIni(rIni), rangeEnd(rEnd) {};
//};
//
//
//
//
//class EmptyVectorExc : public logic_error {
//public:
//	EmptyVectorExc(const string& m) : logic_error("Empty vector. " + m) {};
//};
//
