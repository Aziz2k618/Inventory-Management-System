
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<sstream>

using namespace std;

class Product
{
protected:
	string name;
	string brand;
	string category;
	int product_id;
	double price;
	int quantity;
public:
	
	Product() :name(""), brand(""), category(""), product_id(0), price(0.0), quantity(0) {}

	
	Product(string n, string b, string c, int id, double p, int q) :
		name(n), brand(b), category(c), product_id(id), price(p), quantity(q) {
	}

	friend class Operations;
};

class Operations : public Product
{
	vector<Product> Inventory;

public:
	Operations() {
		load_from_file();
	    preloaded_products();
	}

	
	void Addproduct()
	{
		Product p;

		cout << "Enter the name: ";
		cin >> p.name;
		cout << endl;

		cout << "Enter the brand: ";
		cin >> p.brand;
		cout << endl;


		cout << "Enter the category: ";
		cin >> p.category;
		cout << endl;

		cout << "Enter the ID: ";
		cin >> p.product_id;
		cout << endl;

		cout << "Enter the price: ";
		cin >> p.price;
		cout << endl;

		cout << "enter the Quantity: ";
		cin >> p.quantity;
		cout << endl;

		Inventory.push_back(p);
		cout << "Product added succesfully to the Inventory"<<endl;
	}
	void save_to_file()
	{
		ofstream file("Inventory.txt");
		if (file.is_open()) {
			for (auto& p : Inventory) {
				{
					file << p.product_id << "," << p.name << "," << p.brand << "," << p.category << "," << p.price << "," << p.quantity << endl;
				}file.close();
			}
		}
		else
			cout << "Error Opening the File!" << endl;
	}

	
	void Viewproducts() {
		if (Inventory.empty()) {
			cout << "There is no product in Inventory"<<endl;
		}
		cout << left  << setw(18) << "Name" << setw(18) << "Brand" << setw(10) << "Category" << setw(10) << "ID" << setw(12) << "Price" << setw(10)
			<< "Quantity" << endl;
		cout << string(86, "-")<<endl;
		
		for (Product& p : Inventory) {
			cout << left << setw(18) << p.name << setw(18) << p.brand << setw(18) << p.category << setw(10) << p.product_id << setw(12)<<fixed<<setprecision(2) << p.price << setw(10)
				<< p.quantity << endl;
		}

	}void SellProducts()
	{
	
		int id;
		cout << "Enter the Product ID: ";
		cin >> id;
		for(Product& p:Inventory){
			if (p.product_id == id)
			{
				cout << "Enter the number of items you want to sell: ";
				int items;
				cin >> items;
				
				if (items <= p.quantity)
				{
					p.quantity -= items;
					double total;
					cout << "Quantity updated succesfully!" << endl;
					total = items * p.price;
					cout << "Bill:\nProduct ID: " << p.product_id << "\nQuantity: " << p.quantity << "\nPrice: " << p.price << "\nTotal Amount: " << total << endl;
					return;
				}

				cout << "Not Enough Quantity!" << endl;
				return;
			}
		}
			cout << "No Product Fouund!" << endl;

		
	}
	void Update_Product()
	{
		
		int id,num;
		cout << "Enter the Product ID: ";
		cin >> id;

		
		for (Product& p : Inventory) {
			if (id == p.product_id)
			{

				cout << "Current Product Details: " << endl;
				cout << "Name: " << p.name << endl;
				cout << "Brand: " << p.brand << endl;
				cout << "Price: " << p.price << endl;
				cout << "Quantity " << p.quantity << endl;
do {
				int select;
				cout << "Update :" << endl;
				cout << "1-Name" << endl;
				cout << "2-Brand" << endl;
				cout << "3-Price" << endl;
				cout << "4-Quantity" << endl;
				cout << "0-Exit" << endl;
				cout << "Select the data you want to Update! : ";
				cin >> select;

				switch (select)
				{
				case 1: {
					string n;
					cout << "Enter The New Name: ";
					cin >> n;
					p.name = n;
					cout << "Name Updated Succesfully!" << endl;
					break;
				}
				case 2: {
					string b;
					cout << "Enter The New Brand: ";
					cin >> b;
					p.brand = b;
					cout << "Brand Updated Succesfully!" << endl;
					break;
				}
				case 3:
				{
					double newprice;
					cout << "Enter The New Price: ";
					cin >> newprice;
					p.price = newprice;
					cout << "Price Updated Succesfully!" << endl;
					break;
				}
				case 4:
				{
					int q;
					cout << "Enter The New Quantity: ";
					cin >> q;
					p.quantity = q;
					cout << "Quantity Updated Succesfully!" << endl;
					break;
				}
				case 0:
					break;
				default:
					cout << "Wrong Choice Entered!" << endl;
					break;
				}while (num != 0);
			}
			}
		if(id!=p.product_id)
			cout << "No Product found!"<<endl;
	}
	void load_from_file()
	{
		ifstream file("Inventory.txt");
		string line;
		while (getline(file, line)) {
			stringstream ss(line);
			string name, brand, category, temp;
			int id, qty;
			double price;

			getline(ss, temp, ','); id = stoi(temp);
			getline(ss, temp, ',');
			getline(ss, temp, ',');
			getline(ss, temp, ',');
			getline(ss, temp, ',');price = stoi(temp);
			getline(ss, temp, ',');qty = stoi(temp);
			Inventory.emplace_back(name, brand, category, id, price, qty);
		}
		file.close();

	}
	void DeleteProduct()
	{
		
		int id;
		cout << "Enter the Product ID: ";
		cin >> id;
		for (auto it = Inventory.begin();it != Inventory.end();it++)
		{
			if (it->product_id = id)
			{
				Inventory.erase(it);
				cout << "Product Deleted Succesfully" << endl;
				return;

			}cout << "Product not found" << endl;
		}
	}
	void Exit_Program()
	{
		cout << "Exiting...." << endl;
		exit(0);
	}void preloaded_products()
	{
		if (Inventory.empty()) {
			Inventory.push_back(Product("Laptop", "Dell", "Electronics", 1001, 75000, 10));
			Inventory.push_back(Product("Smartphone", "Samsung", "Electronics", 1002, 55000, 15));
			Inventory.push_back(Product("Headphones", "Sony", "Accessories", 1003, 8000, 25));
			Inventory.push_back(Product("Keyboard", "Logitech", "Accessories", 1004, 3500, 30));
			Inventory.push_back(Product("Monitor", "HP", "Electronics", 1005, 22000, 12));
			Inventory.push_back(Product("Mouse", "Dell", "Accessories", 1006, 1500, 40));
			Inventory.push_back(Product("Tablet", "Lenovo", "Electronics", 1007, 30000, 8));
			Inventory.push_back(Product("Printer", "Canon", "Electronics", 1008, 18000, 7));
			Inventory.push_back(Product("Router", "TP-Link", "Networking", 1009, 2500, 20));
			Inventory.push_back(Product("Webcam", "Logitech", "Accessories", 1010, 4200, 18));
			Inventory.push_back(Product("Smartwatch", "Amazfit", "Wearables", 1011, 10000, 14));
			Inventory.push_back(Product("Speaker", "JBL", "Audio", 1012, 7000, 16));
			Inventory.push_back(Product("Hard Drive", "Seagate", "Storage", 1013, 6000, 22));
			Inventory.push_back(Product("SSD", "Samsung", "Storage", 1014, 9000, 11));
			Inventory.push_back(Product("Charger", "Anker", "Accessories", 1015, 2200, 35));
			Inventory.push_back(Product("Power Bank", "Mi", "Accessories", 1016, 2500, 27));
			Inventory.push_back(Product("Graphics Card", "NVIDIA", "Components", 1017, 45000, 5));
			Inventory.push_back(Product("Motherboard", "ASUS", "Components", 1018, 15000, 9));
			Inventory.push_back(Product("RAM", "Corsair", "Components", 1019, 7000, 13));
			Inventory.push_back(Product("Cooling Fan", "Cooler Master", "Components", 1020, 3000, 19));
		}
	}
};
	

int main()
{
	Operations obj;
	int choice;
	do{
		cout << " --------Iventory Management System----------" << endl;
		cout << " 1-Add a Product" << endl;
		cout << " 2-View a Product" << endl;
		cout << " 3-Sell a Product" << endl;
		cout << " 4-Update a Product" << endl;
		cout << " 5-Delete a Product" << endl;
		cout << " 6-EXIT" << endl;

		
		cin >> choice;
		switch (choice){
		case 1:
			obj.Addproduct();
			break;
		case 2:
			obj.Viewproducts();
			break;
		case 3:
			obj.SellProducts();
			break;
		case 4:
			obj.Update_Product();
			break;
		case 5:
			obj.DeleteProduct();
			break;
		case 6:
			obj.Exit_Program();
			break;
		default:
			cout << "Invalid Choice Entered!" << endl;
		}
				
	} while (choice != 6);

		return 0;
	 
}