# **RayCaster**

A engine project 2D/3D made with the *olc::PixelGameEngine* that utilises the **raycasting technique**, used to render a 3D environment based on a 2D grid.

---

## Project Preview

* 2D View

![alt text](2D_cut.gif)

* 3D View

![alt text](3D_cut.gif)

---

## **How To Run**

* **Prerequisites**

You need the following installed and configured:

* **G++ Compiler:** Accessible via your system's **PATH** environment variable.
* **Visual Studio Code (VS Code):** The recommended editor, which uses the project's built-in tasks.

### **Build & Execution**

The project is configured to be built and run using **two distinct VS Code tasks** to ensure the correct working directory is always used for asset loading.

* **Build the Project:**

    * Open the project folder in **VS Code**.
    * Press **`Ctrl + Shift + B`** (or go to Terminal > Run Build Task).
    * VS Code will run the task, compiling all source files and saving the executable to the **`build/` folder**.

* **Run the Game:**

    * Press **`Ctrl + Shift + P`** to open the Command Palette.
    * Type **`Tasks: Run Task`** and select **`Run RayCaster`**.

This executes the game from the project root, allowing it to correctly find your **`assets/Map.txt`** file.