# Employee and Inventory Management System

## Description
This application is a console-based management system designed to handle employees, inventory, orders, and reports for a business. The system allows for adding, modifying, deleting, and displaying employees, products in stock, and order details. It also generates reports based on employee performance and stock management.

## Features
- **Employee Management**: Add, remove, modify, and view employee details.
- **Inventory Management**: Add, remove, modify, and view product details.
- **Order Management**: View order details and process orders.
- **Reports Generation**: Generate reports based on employee performance and sales data.

## File Structure
```
├── headers/
│   ├── angajat.h
│   ├── functii_angajati.h
│   ├── functii_comenzi.h
│   ├── functii_stoc.h
│   ├── functii_raport.h
├── source/
│   ├── angajat.cpp
│   ├── persoana.cpp
│   ├── functii_angajati.cpp
│   ├── functii_stoc.cpp
│   ├── comanda.cpp
│   ├── disc_vint.cpp
│   ├── disc.cpp
│   ├── produs.cpp
│   ├── vestimentatie.cpp
│   ├── functii_comenzi.cpp
│   ├── operator.cpp
│   ├── functii_raport.cpp
├── data_in/
│   ├── info_angajati.in
│   ├── info_stoc.in
│   ├── info_comenzi.in
├── data_out/
│   ├── ang_cele_mai_multe_comenzi.csv
│   ├── top3_ang_val.csv
│   ├── top3_ang_sal.csv
├── main.cpp
├── Makefile
```

## Installation & Compilation
### Prerequisites
- C++ compiler (e.g., g++)
- Standard C++ libraries

### Compilation Command
To compile the application, use the Makefile:
```sh
make
```

### Running the Application
```sh
./magazin
```

### Cleaning Up
To remove the compiled binary:
```sh
make clean
```

## Usage Guide
1. **Main Menu Options**
   - **1: Employee Management**
   - **2: Inventory Management**
   - **3: Order Management**
   - **4: Generate Reports**
   - **0: Exit the program**

2. **Employee Management Submenu**
   - Add, modify, delete, or display employee details.

3. **Inventory Management Submenu**
   - Add, modify, delete, or display product details.

4. **Order Management Submenu**
   - View and process orders.

5. **Reports Submenu**
   - Generate employee performance and sales reports.

## Data Files
- `data_in/info_angajati.in`: Contains employee details.
- `data_in/info_stoc.in`: Contains product inventory details.
- `data_in/info_comenzi.in`: Contains order details.
- `data_out/`: Stores generated reports.

## Contributing
Feel free to contribute by improving functionalities, fixing bugs, or optimizing performance.

## License
This project is open-source and free to use under the MIT License.

