#include "src/Application.hpp"
#include "src/AllegroException.hpp"
#include "src/Actor.hpp"
#include "src/Application.hpp"
#include "src/ResourceNotLoaded.hpp"

int main(int argc, char** argv) {
	{
		Application app;
		try {
			app.init(argc, argv);
			app.loop();
		}
		catch (AllegroException &e) {
			std::cout << e.what() << std::endl;
			system("pause");
		}
		catch (ResourceNotLoaded &e) {
			std::cerr << e.what() << std::endl;
			system("pause");

		}
	}

	return 0;
}



