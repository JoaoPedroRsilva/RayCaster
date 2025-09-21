# RayCaster
Ray Caster implementation in C++ using PixelGameEngine. This is a personal project with the main goal of learning
concepts learned :
- C++ language
- More familiarized with the compiling process:
When We use a comand to build/compile the code the compiler driver executes 3 steps, the pre-processing, 
compiling and the linker. In the pre-processing step the Pre-processor copies the contents of the header files
into the source code files, essencially preparing the code so all the declarations are available for the compiling, the declarations act as a promise to the compiler, for example when the compiler sees a method that is not defined in the current class it will compile even without know what the method does. The compiling process basicaly translates all the source code into machine code, wich is a binary version of an assembly language, the compiler does this to all the source code files individually and the translated file is an .o or .obj file, the compiler also leaves a "space" for all the calls that only have a declaration but not a definition so they can be linked int the next step. The Linker step does exactly that, it links all the missing definitions that where left open in the last step so that the executable can be created.

- Utilização de headers para modularizar o codigo e facilitar uma futura expansão se necessario. Utilização da intrução de pré-processamento #include.
    - processo de pre processamento compilação e linkagem do codigo para gerar o executavel
