#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ID_ID_ID[10];
char ITEM_PRICE[8];
char ITEM_ID[10];

typedef struct Admin {
	char Admin_ID[10];		// AD1001
	char Password[10];		// 123456
	struct Admin* next;
}Admin;

typedef struct Customer {
	char Customer_ID[10];	// CU1001
	char Name[20];			// Jay
	char Password[10];		// qwerty
	char Phone[15];			// 012-3456789
	char Email[30];			// Jay@dosta.com.my
	char DOB[10];			// 31/08/1957 (DD/MM/YYYY)
	struct Customer* next;
}Customer;

typedef struct Items {
	char Item_ID[10];		// IT1001
	char Product[30];		// Coffee
	float Price;			// 8.99
	struct Items* next;
}Items;

typedef struct Item {
	char Item_ID[10];		// IT1001
	char Product[30];		// Coffee
	char Price[8];			// 8.99
	struct Item* next;
}Item;


typedef struct Order {
	char Order_ID[10];		// OR1001
	char Customer_ID[10];	// CU001
	char Item_ID[10];		// IT001
	unsigned int Quantity;	// 4
	float Price;			// 8.99
	float Total;			// 35.96
	char Status[15];		// In_Progress
	struct Order* next;
}Order;

typedef struct Orders {
	char Order_ID[10];		// OR1001
	char Customer_ID[10];	// CU001
	char Item_ID[10];		// IT001
	char Quantity[10];		// 4
	char Price[10];			// 8.99
	char Total[10];			// 35.96
	char Status[15];		// In_Progress
	struct Orders* next;
}Orders;

admin_login();
customer_register();
customer_login();
Admin_what_do_you_want_to_do();
Customer_what_do_you_want_to_do();
Add_item();
Modify_item();
Modify_product();
Modify_price();
View_Item();
Search_item();
Search_item_id();
Search_item_keywords();
Admin_view_order();
Admin_search_order();
Admin_search_order_CID();
Admin_search_order_OID();
complete_order();
Place_order();
Customer_view_order();
char* check_item();
char* item_price();
cancel_order();
view_personal_information();
edit_personal_information();
modify_customer_name();
modify_customer_password();
modify_customer_phone();
modify_customer_email();
Customer* Customer_list();
Admin* Admin_list();
Item* Item_list();
Orders* Orders_list();

main() {
	int choice = 0;
	printf("\n\n\n Who are you? \n");
	printf("\n\t 1. Admin \n\t 2. New Customer \n\t 3. Registered Customer \n\t 4. Exit \n");
	printf("\n Choose the operation from the given option: ");
	scanf("%d", &choice);

	if (choice <= 0 || choice > 4) {
		printf("\n Invalid input. Please try again. \n\n");
		main();
	}
	else if (choice == 1) {
		printf("\n Welcome, Admin. \n");
		admin_login();
	}
	else if (choice == 2) {
		printf("\n Welcome, New Customer. Please Register. \n");
		customer_register();
	}
	else if (choice == 3) {
		printf("\n Welcome, Registered Customer. \n");
		customer_login();
	}
	else {
		printf("\n Thank You for using Dosta Coffee Shop ordering system. Bye Bye.\n\n\n");
		exit(0);
	}
	main();
}

admin_login() {
	int cont = 0;
	char ID[10], password[10];
	printf("\n\n Enter Your Admin ID: ");
	scanf("%s", &ID);
	rewind(stdin);
	printf(" Enter Your Password: ");
	scanf("%s", &password);
	rewind(stdin);

	Admin* Adm;
	Adm = Admin_list();
	while (Adm != NULL) {
		if (strcmp(Adm->Admin_ID, ID) == 0 && strcmp(Adm->Password, password) == 0) {
			printf("\n Login successfully!!!");
			cont = 1;
			strcpy(ID_ID_ID, ID);
			Admin_what_do_you_want_to_do();
			break;
		}
		Adm = Adm->next;
		cont = 0;
	}
	if (cont == 0) {
		printf("\n Wrong Customer ID or Password. Please try again.");
		main();
	}
}

customer_register() {
	char Name[10];
	int i = 1;
	char line[100];
	char id_num[5] = "", ID[10] = "CU";
	Customer Cus;
	FILE* fptr = fopen("Customer.txt", "a+");
	while (fgets(line, sizeof(line), fptr) != NULL) {
		i++;
	}
	i = i + 1000;
	_itoa(i, id_num, 10);
	strcat(ID, id_num);
	rewind(stdin);
	printf("\n\n Enter Your Name (No Spaces): ");
	scanf("%s", &Cus.Name);
	rewind(stdin);
	printf(" Enter Your Password: ");
	scanf("%s", &Cus.Password);
	rewind(stdin);
	printf(" Enter Your Phone Number (No Spaces): ");
	scanf("%s", &Cus.Phone);
	rewind(stdin);
	printf(" Enter Your Email: ");
	scanf("%s", &Cus.Email);
	rewind(stdin);
	printf(" Enter Your Date Of Birth (DD/MM/YYYY): ");
	scanf("%s", &Cus.DOB);
	rewind(stdin);
	printf("\n Hi %s, Your Customer ID is %s. Please Login as registered customer to continue using the system. \n\n\n", Cus.Name, ID);
	fprintf(fptr, "%s,%s,%s,%s,%s,%s\n", ID, Cus.Name, Cus.Password, Cus.Phone, Cus.Email, Cus.DOB);
	fclose(fptr);
}

customer_login() {
	int cont = 0;
	char ID[10], password[10];
	printf("\n\n Enter Your Customer ID: ");
	scanf("%s", &ID);
	rewind(stdin);
	printf(" Enter Your Password: ");
	scanf("%s", &password);
	rewind(stdin);

	Customer* Cus;
	Cus = Customer_list();
	while (Cus != NULL) {
		if (strcmp(Cus->Customer_ID, ID) == 0 && strcmp(Cus->Password, password) == 0) {
			printf("\n Login successfully!!!");
			cont = 1;
			strcpy(ID_ID_ID, ID);
			Customer_what_do_you_want_to_do();
			break;
		}
		Cus = Cus->next;
		cont = 0;
	}
	if (cont == 0) {
		printf("\n Wrong Customer ID or Password. Please try again.");
		main();
	}
}

Admin_what_do_you_want_to_do() {
	int choice = 0;
	printf("\n\n\n What do you want to do by using DOSTA COFEE SHOP ORDERING SYSTEM? \n\n");
	printf("\t 1. Add Item \n");
	printf("\t 2. Modify Item \n");
	printf("\t 3. View All Items \n");
	printf("\t 4. Search Item \n");
	printf("\t 5. View All Orders \n");
	printf("\t 6. Search Order \n");
	printf("\t 7. Change Order Status To Complete \n");
	printf("\t 8. Create Customer Account \n");
	printf("\t 9. Logout \n");
	printf("\n Choose the operation from the given option: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		Add_item();
		break;
	case 2:
		Modify_item();
		break;
	case 3:
		View_Item();
		break;
	case 4:
		Search_item();
		break;
	case 5:
		Admin_view_order();
		break;
	case 6:
		Admin_search_order();
		break;
	case 7:
		complete_order();
		break;
	case 8:
		customer_register();
		break;
	case 9:
		main();
		break;
	default:
		printf("\n Invalid input. Please try again. \n\n");
		break;
	}
	Admin_what_do_you_want_to_do();
}

Customer_what_do_you_want_to_do() {
	int choice = 0;
	printf("\n\n\n What do you want to do by using DOSTA COFEE SHOP ORDERING SYSTEM? \n\n");
	printf("\t 1. View All Items \n");
	printf("\t 2. Place Order and Make Payment \n");
	printf("\t 3. View Order \n");
	printf("\t 4. Cancel Order \n");
	printf("\t 5. Search Item \n");
	printf("\t 6. View Personal Information \n");
	printf("\t 7. Edit Personal Information \n");
	printf("\t 8. Logout \n");
	printf("\n Choose the operation from the given option: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		View_Item();
		break;
	case 2:
		Place_order();
		break;
	case 3:
		Customer_view_order();
		break;
	case 4:
		cancel_order();
		break;
	case 5:
		Search_item();
		break;
	case 6:
		view_personal_information();
		break;
	case 7:
		edit_personal_information();
		break;
	case 8:
		main();
		break;
	default:
		printf("\n Invalid input. Please try again. \n\n");
		break;
	}
	Customer_what_do_you_want_to_do();
}

Add_item() {
	char Name[10];
	int i = 1;
	char line[100];
	char id_num[5] = "", ID[10] = "IT";
	Items Ite;
	FILE* fptr = fopen("Item.txt", "a+");
	while (fgets(line, sizeof(line), fptr) != NULL) {
		i++;
	}
	i = i + 1000;
	_itoa(i, id_num, 10);
	strcat(ID, id_num);
	rewind(stdin);
	printf("\n\n Enter the new item (No Spaces): ");
	scanf("%s", &Ite.Product);
	rewind(stdin);
	printf(" Enter the price: RM ");
	scanf("%f", &Ite.Price);
	rewind(stdin);
	printf("\n The Item ID for %s is %s \n\n\n", Ite.Product, ID);
	fprintf(fptr, "%s,%s,%.2f\n", ID, Ite.Product, Ite.Price);
	fclose(fptr);
}

Modify_item() {
	int choice = 0;
	printf("\n\n\n Which information do you want to modify? \n");
	printf("\n\t 1. Item Name \n");
	printf("\t 2. Price \n");
	printf("\t 3. Exit \n");
	printf("\n Choose the operation from the given option: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		Modify_product();
		break;
	case 2:
		Modify_price();
		break;
	case 3:
		break;
	default:
		printf("\n Invalid input. Please try again. \n\n");
		Modify_item();
		break;
	}
}

Modify_product() {
	char New_name[30];
	char ID_ID[10];
	Item* Ite, * p, * current;
	p = Item_list();
	Ite = Item_list();
	FILE* fptr;
	printf("\n Please enter the Item ID: ");
	scanf("%s", &ID_ID);

	while (Ite != NULL) {
		if (strcmp(Ite->Item_ID, ID_ID) == 0) {
			printf("\n\n %s is your actual item name.", Ite->Product);
			break;
		}
		Ite = Ite->next;
	}
	rewind(stdin);
	printf("\n\n Please enter your new item name: ");
	scanf("%s", &New_name);
	rewind(stdin);

	current = p;
	while (p != NULL) {
		if (strcmp(p->Item_ID, ID_ID) == 0) {
			strcpy(p->Product, New_name);
		}
		p = p->next;
	}
	fptr = fopen("Item.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s\n", current->Item_ID, current->Product, current->Price);
		current = current->next;
	}
	fclose(fptr);
}

Modify_price() {
	char New_price[8];
	char ID_ID[10];
	Item* Ite, * p, * current;
	p = Item_list();
	Ite = Item_list();
	FILE* fptr;
	printf("\n Please enter the Item ID: ");
	scanf("%s", &ID_ID);

	while (Ite != NULL) {
		if (strcmp(Ite->Item_ID, ID_ID) == 0) {
			printf("\n\n RM %s is your actual price.", Ite->Price);
			break;
		}
		Ite = Ite->next;
	}
	rewind(stdin);
	printf("\n\n Please enter your new price: RM ");
	scanf("%s", &New_price);
	rewind(stdin);

	current = p;
	while (p != NULL) {
		if (strcmp(p->Item_ID, ID_ID) == 0) {
			strcpy(p->Price, New_price);
		}
		p = p->next;
	}
	fptr = fopen("Item.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s\n", current->Item_ID, current->Product, current->Price);
		current = current->next;
	}
	fclose(fptr);
}

View_Item() {
	Item* Ite;
	Ite = Item_list();

	while (Ite != NULL) {
		printf("\n\n\n Dear user, here is the item. ");
		printf("\n\n\t Item ID: %s", Ite->Item_ID);
		printf("\n\t Item: %s", Ite->Product);
		printf("\n\t Price: RM %s", Ite->Price);
		Ite = Ite->next;
	}
}

Search_item() {
	int choice = 0;
	printf("\n\t 1. Search Item by Item ID \n");
	printf("\t 2. Search Item by keywords \n");
	printf("\n Choose the operation from the given option: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		Search_item_id();
		break;
	case 2:
		Search_item_keywords();
		break;
	default:
		printf("\n Invalid input. Please try again. \n\n");
		Search_item();
		break;
	}
}

Search_item_id() {
	int ready = 0;
	Item* Ite;
	char ID_ID[10];
	Ite = Item_list();
	printf("\n Please enter the Item ID: ");
	scanf("%s", &ID_ID);

	while (Ite != NULL) {
		if (strcmp(Ite->Item_ID, ID_ID) == 0) {
			printf("\n\n\n Dear user, here is the item. ");
			printf("\n\n\t Item ID: %s", Ite->Item_ID);
			printf("\n\t Item: %s", Ite->Product);
			printf("\n\t Price: RM %s", Ite->Price);
			
			ready = 1;
		}
		Ite = Ite->next;
	}

	if (ready == 0) {
		printf("\n Item not found.");
	}
}

Search_item_keywords() {
	int done = 0;
	char keywords[8], line[50];
	Item temp;
	printf("\n Enter the keywords: ");
	scanf("%s", keywords);
	rewind(stdin);
	FILE* fptr = fopen("Item.txt", "r");
	while (fgets(line, sizeof(line), fptr) != NULL) {
		if (strstr(line, keywords) != NULL) {
			printf("\n Item ID, Item, Price");
			printf("\n %s", line);
			done = 1;
		}
	}
	if (done == 0) {
		printf("\n Item not found.");
	}
	fclose(fptr);
}

Admin_view_order() {
	Orders* Ord;
	Ord = Orders_list();

	while (Ord != NULL) {
		printf("\n\n\t Order ID: %s \t Customer ID: %s \t Item ID: %s \t Quantity: %s", Ord->Order_ID, Ord->Customer_ID, Ord->Item_ID, Ord->Quantity);
		printf("\n\t Price: RM %s \t Total: RM %s \t Status: %s", Ord->Price, Ord->Total, Ord->Status);
		Ord = Ord->next;
	}
}

Admin_search_order() {
	int choice = 0;
	printf("\n\t 1. Search Order by Customer ID \n");
	printf("\t 2. Search Order by Order ID \n");
	printf("\n Choose the operation from the given option: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		Admin_search_order_CID();
		break;
	case 2:
		Admin_search_order_OID();
		break;
	default:
		printf("\n Invalid input. Please try again. \n\n");
		Admin_search_order();
		break;
	}
}

Admin_search_order_CID() {
	int ready = 0;
	Orders* Ord;
	char ID_ID[10];
	Ord = Orders_list();
	printf("\n Please enter the Customer ID: ");
	scanf("%s", &ID_ID);

	while (Ord != NULL) {
		if (strcmp(Ord->Customer_ID, ID_ID) == 0) {
			printf("\n\n\t Order ID: %s \t Customer ID: %s \t Item ID: %s \t Quantity: %s", Ord->Order_ID, Ord->Customer_ID, Ord->Item_ID, Ord->Quantity);
			printf("\n\t Price: RM %s \t Total: RM %s \t Status: %s", Ord->Price, Ord->Total, Ord->Status);
			ready = 1;
		}
		Ord = Ord->next;
	}
	if (ready == 0) {
		printf("\n Id not found.");
	}
}

Admin_search_order_OID() {
	int ready = 0;
	Orders* Ord;
	char ID_ID[10];
	Ord = Orders_list();
	printf("\n Please enter the Order ID: ");
	scanf("%s", &ID_ID);

	while (Ord != NULL) {
		if (strcmp(Ord->Order_ID, ID_ID) == 0) {
			printf("\n\n\t Order ID: %s \t Customer ID: %s \t Item ID: %s \t Quantity: %s", Ord->Order_ID, Ord->Customer_ID, Ord->Item_ID, Ord->Quantity);
			printf("\n\t Price: RM %s \t Total: RM %s \t Status: %s", Ord->Price, Ord->Total, Ord->Status);
			ready = 1;
		}
		Ord = Ord->next;
	}
	if (ready == 0) {
		printf("\n ID not found");
	}
}

complete_order() {
	char New_status[20], Completed[10];
	Orders* p, * current;
	p = Orders_list();
	FILE* fptr;
	int cancel = 0;

	printf("\n Which order do you want to change status to complete? ");
	printf("\n Please fill in the Order ID here: ");
	rewind(stdin);
	scanf("%s", &Completed);
	rewind(stdin);

	strcpy(New_status, "Completed");

	current = p;
	while (p != NULL) {
		if (strcmp(p->Order_ID, Completed) == 0) {
			strcpy(p->Status, New_status);
			cancel = 1;
			break;
		}
		p = p->next;
	}
	fptr = fopen("Order.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s,%s,%s,%s,%s\n", current->Order_ID, current->Customer_ID, current->Item_ID, current->Quantity, current->Price, current->Total, current->Status);
		current = current->next;
	}
	fclose(fptr);

	if (cancel == 1) {
		printf("\n Order status changed to complete!!! \n\n");
	}
	else {
		printf("\n Order status had not changed to complete!!! \n\n");
	}
}

Place_order() {
	int i = 1;
	char ID_ID[10], line[100];
	char item_price1[8];
	char id_num[5] = "", ID[10] = "OR";
	Order Ord;
	FILE* fptr = fopen("Order.txt", "a+");
	while (fgets(line, sizeof(line), fptr) != NULL) {
		i++;
	}
	i = i + 1000;
	_itoa(i, id_num, 10);
	strcat(ID, id_num);
	strcpy(Ord.Customer_ID, ID_ID_ID);
	check_item();
	strcpy(Ord.Item_ID, ITEM_ID);

	rewind(stdin);
	printf(" Enter the quantity of the item you want to order: ");
	scanf("%d", &Ord.Quantity);
	rewind(stdin);

	item_price();
	printf("\n The price of %s is RM %s. ", ITEM_ID, ITEM_PRICE);
	Ord.Price = atof(ITEM_PRICE);

	Ord.Total = Ord.Quantity * Ord.Price;
	strcpy(Ord.Status, "In_Progress");
	printf(" The total of your order is RM %.2f", Ord.Total);

	fprintf(fptr, "%s,%s,%s,%d,%.2f,%.2f,%s\n", ID, Ord.Customer_ID, Ord.Item_ID, Ord.Quantity, Ord.Price, Ord.Total, Ord.Status);
	fclose(fptr);
}

char* item_price() {
	Item* Ite;
	Ite = Item_list();
	while (Ite != NULL) {
		if (strcmp(Ite->Item_ID, ITEM_ID) == 0) {
			strcpy(ITEM_PRICE, Ite->Price);
			return Ite->Price;
		}
		Ite = Ite->next;
	}
}

char* check_item() {
	char line[100], ID_ID[10];
	printf("\n Enter the ID of the item you want to order: ");
	scanf("%s", ITEM_ID);
	FILE* fptr = fopen("Item.txt", "r");
	while (fgets(line, sizeof(line), fptr) != NULL) {
		if (strstr(line, ITEM_ID) != NULL) {
			return ITEM_ID;
		}
	}
	fclose(fptr);
	printf("\n\n Item not found!!! ");
	Customer_what_do_you_want_to_do();
}

Customer_view_order() {
	int ready = 0;
	Orders* Ord;
	Ord = Orders_list();
	while (Ord != NULL) {
		if (strcmp(Ord->Customer_ID, ID_ID_ID) == 0) {
			printf("\n\n\n Dear customer, here is your order. ");
			printf("\n\n\t Order ID: %s", Ord->Order_ID);
			printf("\n\t Customer ID: %s", Ord->Customer_ID);
			printf("\n\t Item ID: %s", Ord->Item_ID);
			printf("\n\t Quantity: %s", Ord->Quantity);
			printf("\n\t Price: RM %s", Ord->Price);
			printf("\n\t Total: RM %s", Ord->Total);
			printf("\n\t Status: %s", Ord->Status);
			ready = 1;
		}
		Ord = Ord->next;
	}
	if (ready == 0) {
		printf("\n Dear customer, you have not make any order yet.");
	}
}

cancel_order() {
	char New_status[20], deleted[10];
	Orders* p, * current;
	p = Orders_list();
	FILE* fptr;
	int cancel = 0;

	printf("\n Which order do you want to cancel? ");
	printf("\n Please fill in the Order ID here: ");
	rewind(stdin);
	scanf("%s", &deleted);
	rewind(stdin);

	strcpy(New_status, "Cancelled");

	current = p;
	while (p != NULL) {
		if (strcmp(p->Order_ID, deleted) == 0) {
			if (strcmp(p->Customer_ID, ID_ID_ID) == 0) {
				strcpy(p->Status, New_status);
				cancel = 1;
				break;
			}
		}
		p = p->next;
	}
	fptr = fopen("Order.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s,%s,%s,%s,%s\n", current->Order_ID, current->Customer_ID, current->Item_ID, current->Quantity, current->Price, current->Total, current->Status);
		current = current->next;
	}
	fclose(fptr);

	if (cancel == 1) {
		printf("\n Order cancelled successfully!!! \n\n");
	}
	else {
		printf("\n Order cancelled unsuccessfully!!! \n\n");
	}
}

view_personal_information() {
	Customer* Cus;
	Cus = Customer_list();
	while (Cus != NULL) {
		if (strcmp(Cus->Customer_ID, ID_ID_ID) == 0) {
			printf("\n\n\n Dear customer, here is your information. ");
			printf("\n\n\t Customer ID: %s", Cus->Customer_ID);
			printf("\n\t Name: %s", Cus->Name);
			printf("\n\t Password: %s", Cus->Password);
			printf("\n\t Phone: %s", Cus->Phone);
			printf("\n\t Email: %s", Cus->Email);
			printf("\n\t DOB: %s", Cus->DOB);
		}
		Cus = Cus->next;
	}
}

edit_personal_information() {
	int choice = 0;
	printf("\n\n\n Which information do you want to modify? \n");
	printf("\n\t 1. Name \n");
	printf("\t 2. Password \n");
	printf("\t 3. Phone \n");
	printf("\t 4. Email \n");
	printf("\t 5. Exit \n");
	printf("\n Choose the operation from the given option: ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		modify_customer_name();
		break;
	case 2:
		modify_customer_password();
		break;
	case 3:
		modify_customer_phone();
		break;
	case 4:
		modify_customer_email();
		break;
	case 5:
		break;
	default:
		printf("\n Invalid input. Please try again. \n\n");
		edit_personal_information();
		break;
	}
}

modify_customer_name() {
	char New_name[20];
	Customer* Cus, * p, * current, * head;
	p = Customer_list();
	Cus = Customer_list();
	FILE* fptr;

	while (Cus != NULL) {
		if (strcmp(Cus->Customer_ID, ID_ID_ID) == 0) {
			printf("\n\n %s is your actual name.", Cus->Name);
			break;
		}
		Cus = Cus->next;
	}
	rewind(stdin);
	printf("\n\n Please enter your new name: ");
	scanf("%s", &New_name);
	rewind(stdin);

	current = p;
	while (p != NULL) {
		if (strcmp(p->Customer_ID, ID_ID_ID) == 0) {
			strcpy(p->Name, New_name);
		}
		p = p->next;
	}
	fptr = fopen("Customer.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s,%s,%s,%s\n", current->Customer_ID, current->Name, current->Password, current->Phone, current->Email, current->DOB);
		current = current->next;
	}
	fclose(fptr);
}

modify_customer_password() {
	char new_password[10];
	Customer* Cus, * p, * current, * head;
	p = Customer_list();
	Cus = Customer_list();
	FILE* fptr;

	while (Cus != NULL) {
		if (strcmp(Cus->Customer_ID, ID_ID_ID) == 0) {
			printf("\n\n %s is your actual password.", Cus->Password);
			break;
		}
		Cus = Cus->next;
	}
	rewind(stdin);
	printf("\n\n Please enter your new password: ");
	scanf("%s", &new_password);
	rewind(stdin);

	current = p;
	while (p != NULL) {
		if (strcmp(p->Customer_ID, ID_ID_ID) == 0) {
			strcpy(p->Password, new_password);
		}
		p = p->next;
	}
	fptr = fopen("Customer.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s,%s,%s,%s\n", current->Customer_ID, current->Name, current->Password, current->Phone, current->Email, current->DOB);
		current = current->next;
	}
	fclose(fptr);
}

modify_customer_phone() {
	char New_phone[20];
	Customer* Cus, * p, * current, * head;
	p = Customer_list();
	Cus = Customer_list();
	FILE* fptr;

	while (Cus != NULL) {
		if (strcmp(Cus->Customer_ID, ID_ID_ID) == 0) {
			printf("\n\n %s is your actual phone.", Cus->Phone);
			break;
		}
		Cus = Cus->next;
	}
	rewind(stdin);
	printf("\n\n Please enter your new phone: ");
	scanf("%s", &New_phone);
	rewind(stdin);

	current = p;
	while (p != NULL) {
		if (strcmp(p->Customer_ID, ID_ID_ID) == 0) {
			strcpy(p->Phone, New_phone);
		}
		p = p->next;
	}
	fptr = fopen("Customer.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s,%s,%s,%s\n", current->Customer_ID, current->Name, current->Password, current->Phone, current->Email, current->DOB);
		current = current->next;
	}
	fclose(fptr);
}

modify_customer_email() {
	char New_email[20];
	Customer* Cus, * p, * current, * head;
	p = Customer_list();
	Cus = Customer_list();
	FILE* fptr;

	while (Cus != NULL) {
		if (strcmp(Cus->Customer_ID, ID_ID_ID) == 0) {
			printf("\n\n %s is your actual email.", Cus->Email);
			break;
		}
		Cus = Cus->next;
	}
	rewind(stdin);
	printf("\n\n Please enter your new email: ");
	scanf("%s", &New_email);
	rewind(stdin);

	current = p;
	while (p != NULL) {
		if (strcmp(p->Customer_ID, ID_ID_ID) == 0) {
			strcpy(p->Email, New_email);
		}
		p = p->next;
	}
	fptr = fopen("Customer.txt", "w+");
	while (current != NULL) {
		fprintf(fptr, "%s,%s,%s,%s,%s,%s\n", current->Customer_ID, current->Name, current->Password, current->Phone, current->Email, current->DOB);
		current = current->next;
	}
	fclose(fptr);
}

Customer* Customer_list() {
	Customer* currentPtr = NULL, * node, * x = NULL, temp;
	FILE* fptr;
	fptr = fopen("Customer.txt", "r");

	if (fptr == NULL) {
		printf("File does not exist.");
		return;
	}

	while (fscanf(fptr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", temp.Customer_ID, temp.Name, temp.Password, temp.Phone, temp.Email, temp.DOB) != EOF) {
		node = (Customer*)malloc(sizeof(Customer));
		strcpy(node->Customer_ID, temp.Customer_ID);
		strcpy(node->Name, temp.Name);
		strcpy(node->Password, temp.Password);
		strcpy(node->Phone, temp.Phone);
		strcpy(node->Email, temp.Email);
		strcpy(node->DOB, temp.DOB);
		if (x == NULL) {
			currentPtr = x = node;
		}
		else {
			currentPtr = currentPtr->next = node;
		}
		currentPtr->next = NULL;
	}
	fclose(fptr);
	return x;
}

Admin* Admin_list() {
	Admin* currentPtr = NULL, * node, * x = NULL, temp;
	FILE* fptr;
	fptr = fopen("Admin.txt", "r");

	if (fptr == NULL) {
		printf("File does not exist.");
		return;
	}

	while (fscanf(fptr, "%[^,],%[^\n]\n", temp.Admin_ID, temp.Password) != EOF) {
		node = (Admin*)malloc(sizeof(Admin));
		strcpy(node->Admin_ID, temp.Admin_ID);
		strcpy(node->Password, temp.Password);
		if (x == NULL) {
			currentPtr = x = node;
		}
		else {
			currentPtr = currentPtr->next = node;
		}
		currentPtr->next = NULL;
	}
	fclose(fptr);
	return x;
}

Item* Item_list() {
	Item* currentPtr = NULL, * node, * x = NULL, temp;
	FILE* fptr;
	fptr = fopen("Item.txt", "r");

	if (fptr == NULL) {
		printf("File does not exist.");
		return;
	}

	while (fscanf(fptr, "%[^,],%[^,],%[^\n]\n", temp.Item_ID, temp.Product, temp.Price) != EOF) {
		node = (Item*)malloc(sizeof(Item));
		strcpy(node->Item_ID, temp.Item_ID);
		strcpy(node->Product, temp.Product);
		strcpy(node->Price, temp.Price);
		if (x == NULL) {
			currentPtr = x = node;
		}
		else {
			currentPtr = currentPtr->next = node;
		}
		currentPtr->next = NULL;
	}
	fclose(fptr);
	return x;
}

Orders* Orders_list() {
	Orders* currentPtr = NULL, * node, * x = NULL, temp;
	FILE* fptr;
	fptr = fopen("Order.txt", "r");

	if (fptr == NULL) {
		printf("File does not exist.");
		return;
	}

	while (fscanf(fptr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", temp.Order_ID, temp.Customer_ID, temp.Item_ID, temp.Quantity, temp.Price, temp.Total, temp.Status) != EOF) {
		node = (Orders*)malloc(sizeof(Orders));
		strcpy(node->Order_ID, temp.Order_ID);
		strcpy(node->Customer_ID, temp.Customer_ID);
		strcpy(node->Item_ID, temp.Item_ID);
		strcpy(node->Quantity, temp.Quantity);
		strcpy(node->Price, temp.Price);
		strcpy(node->Total, temp.Total);
		strcpy(node->Status, temp.Status);
		if (x == NULL) {
			currentPtr = x = node;
		}
		else {
			currentPtr = currentPtr->next = node;
		}
		currentPtr->next = NULL;
	}
	fclose(fptr);
	return x;
}