using namespace std;

#include <string>
#include <stdexcept>
#include <sstream>
#include <stdlib.h>

//ArkanoidError: hereda de logic error y sirve como superclase de todas las dem´as excepciones que definiremos.
//SDLError: Hereda de ArkanoidError y se utiliza para todos los errores relacionados con la inicializacion y uso de SDL
//FileNotFoundError: Hereda de ArkanoidError y se utiliza para todos los errores provocados al no encontrarse un fichero que el programa trata de abrir
//FileFormatError: Hereda de ArkanoidError y se utiliza para los errores provocados en la lectura de los ficheros de nivel y de partida guardada por formato incorrecto.

class ArkanoidError : public logic_error {
public:
	ArkanoidError(const string& e) : logic_error(what() + e) {};
	virtual const char* what()
	{
		return ("hay un error: ");
	}
};
class SDLError : public ArkanoidError {
protected:
	int i;

public:
	SDLError(const string& e, int i) : ArkanoidError(what() + e) {};
	const char* what()
	{ 
		// i = 0 si es sld_error y otra cosa si es img_error
		if (i == 0)
			SDL_GetError();
		else IMG_GetError();
	}
	const char* SDL_GetError()
	{
		return ("Error en sdl: ");
	}

};
class FileNotFoundError : public ArkanoidError {
protected:
	string file;

public:
	FileNotFoundError(const string& e) : ArkanoidError(what() + e), file(e) {};
	const char* what()
	{ 
		return (char*)("archivo no encontrado: "/* + file.c_str()*/);
	}
};




class VectorOutOfRangeExc : public out_of_range {
protected:
	int index;
	int rangeIni;
	int rangeEnd;
public:
	VectorOutOfRangeExc(const string& m, int i, int rIni, int rEnd) :
		out_of_range(m + "Invalid access at pos. " + to_string(i) + ". Valid range is [" +  to_string(rIni) + "," + to_string(rEnd) + "]"), index(i), rangeIni(rIni), rangeEnd(rEnd) {};
};








class EmptyVectorExc : public logic_error {
public:
	EmptyVectorExc(const string& m) : logic_error("Empty vector. " + m) {};
};



const uint DEFAULT_CAPACITY = 5; // Capacidad inicial por defecto

template <class T>
class Vector {
private:
	uint capacity;  // Capacidad actual del array dinámico
	uint count = 0; // Contador del número de elementos
	T* elems;       // Array dinámico de elementos de tipo T

public:
	Vector(int initCap = DEFAULT_CAPACITY);
	~Vector() { delete[] elems; count = 0; elems = nullptr; }
	uint size() const { return count; }
	const T& at(int i) const;
	const T& operator[](int i) const { return elems[i]; }
	T& operator[](int i) { return elems[i]; }
	bool empty() const { return count == 0; }
	void push_back(const T& e); // Pone nuevo elemento al final
	void pop_back(); // Quita último elemento
	void insert(const T& e, int i); // Inserta e en posición iésima (desplazando para abrir hueco)
	void erase(int i); // Borra el elemento de la pos. iésima (desplazando para cerrar hueco)

private:
	void reallocate();
	void shiftRightFrom(int i);
	void shiftLeftFrom(int i);
};

// En las plantillas el código de los métodos va también en el .h

template<class T>
Vector<T>::Vector(int initCap) {
	if (initCap <= 0) throw invalid_argument("Initial capacity must be greater than 0");
	capacity = initCap,
		elems = new T[capacity];
}

template<class T>
const T& Vector<T>::at(int i) const {
	if (i < 0 || i >= count)
		throw ArkanoidError("Error in at", i, 0, count - 1);
	return elems[i];
}

template<class T>
void Vector<T>::push_back(const T& e) {
	if (count == capacity) reallocate();
	elems[count] = e;
	++count;
}

template<class T>
void Vector<T>::pop_back() {
	if (count == 0) throw EmptyVectorExc("Cannot pop");
	--count;
}

template<class T>
void Vector<T>::insert(const T& e, int i) {
	if (i > count) //throw out_of_range("Cannot insert at " + to_string(i));
		throw VectorOutOfRangeExc("Cannot insert. ", i, 0, count);
	if (count == capacity) reallocate();
	shiftRightFrom(i);
	elems[i] = e;
	++count;
}

template<class T>
void Vector<T>::erase(int i) {
	if (empty()) throw EmptyVectorExc("Cannot erase");
	if (i >= count) throw out_of_range("Cannot erase elem at " + to_string(i));
	shiftLeftFrom(i);
	--count;
}


// Private methods

template<class T>
void Vector<T>::shiftRightFrom(int i) {
	for (int j = count; j > i; j--)
		elems[j] = elems[j - 1];
}

template<class T>
void Vector<T>::shiftLeftFrom(int i) {
	for (; i < count - 1; i++)
		elems[i] = elems[i + 1];
}

template<class T>
void Vector<T>::reallocate() {
	capacity = capacity * 2;
	T* newElems = new T[capacity];
	for (int i = 0; i < size(); i++)
		newElems[i] = elems[i];
	delete[] elems;
	elems = newElems;
}

