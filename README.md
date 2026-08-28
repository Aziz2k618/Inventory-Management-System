# 📦 Inventory Management System

A console-based **Inventory Management System** developed in C++ as a collaborative **3-member academic project**.

The system allows users to manage products, track inventory quantities, sell products, update product information, and delete products. Inventory data is stored and loaded using a text file.

## 📖 About the Project

The Inventory Management System is a menu-driven C++ application designed to perform basic inventory management operations.

Each product contains the following information:

* Product ID
* Product Name
* Brand
* Category
* Price
* Quantity

The project was developed as part of our academic coursework to practice **Object-Oriented Programming, STL vectors, file handling, and basic data management in C++**.

## ✨ Features

### ➕ Add Product

Allows the user to add a new product by entering:

* Product name
* Brand
* Category
* Product ID
* Price
* Quantity

### 👀 View Products

Displays all available products in a formatted table containing their:

* Name
* Brand
* Category
* ID
* Price
* Quantity

### 🛒 Sell Product

Allows users to sell products using their Product ID.

The system:

* Checks whether the product exists
* Checks available stock
* Updates the remaining quantity
* Calculates the total bill

### ✏️ Update Product

Allows users to update existing product information:

* Name
* Brand
* Price
* Quantity

### 🗑️ Delete Product

Allows users to remove a product from the inventory using its Product ID.

### 💾 File Handling

The system uses `Inventory.txt` to store inventory information.

Product data is stored in the following format:

```text
Product ID,Name,Brand,Category,Price,Quantity
```

The program loads the existing inventory when it starts and saves the updated inventory when the program exits.

## 🛠️ Technologies & Concepts Used

* **C++**
* Object-Oriented Programming (OOP)
* Classes & Objects
* Inheritance
* Encapsulation
* Friend Classes
* STL `vector`
* File Handling
* `fstream`
* `stringstream`
* `iomanip`
* Console Input/Output

## 📁 Project Structure

```text
Inventory-Management-System/
│
├── main.cpp
├── Inventory.txt
└── README.md
```

### `main.cpp`

Contains the complete C++ implementation of the Inventory Management System.

### `Inventory.txt`

Stores the inventory data used by the application.

### `README.md`

Contains documentation and information about the project.

## ⚙️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/YourUsername/Inventory-Management-System.git
```

### 2. Open the Project

Open the project folder in a C++ compatible IDE such as:

* Visual Studio Code
* Code::Blocks
* Dev-C++
* Visual Studio

### 3. Compile

If you are using `g++`:

```bash
g++ main.cpp -o inventory
```

### 4. Run

On Linux/macOS:

```bash
./inventory
```

On Windows:

```bash
inventory.exe
```

## 🖥️ Main Menu

The application provides the following options:

```text
-------- Inventory Management System ----------
1 - Add a Product
2 - View Products
3 - Sell a Product
4 - Update a Product
5 - Delete a Product
6 - EXIT
```

## 👥 Project Type

This project was developed collaboratively by a **3-member team** as part of an academic coursework project.

The project demonstrates our collective understanding of C++ programming, Object-Oriented Programming, file handling, STL vectors, and basic inventory management operations.

## 📚 Learning Outcomes

Through this project, we practiced:

* Designing and using classes in C++
* Applying Object-Oriented Programming concepts
* Using inheritance and friend classes
* Managing collections with STL vectors
* Reading and writing data using files
* Parsing data using `stringstream`
* Building menu-driven console applications
* Implementing inventory management operations
* Working collaboratively on a programming project

## 🚀 Future Improvements

Some possible improvements for the project include:

* 🔐 User authentication and login
* 🔎 Product search and filtering
* ✅ Better input validation
* 📊 Inventory statistics and reports
* ⚠️ Low-stock notifications
* 🧾 Improved invoice generation
* 📜 Sales history
* 🗄️ Database integration
* 🖥️ Graphical User Interface (GUI)

## 📌 Note

This project was created for **educational purposes** as part of academic coursework.
