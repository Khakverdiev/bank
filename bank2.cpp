#include "bank2.h"

std::uniform_int_distribution<int> range(00000000, 99999999);
std::default_random_engine engine(time(nullptr));

std::uniform_int_distribution<int> range1(1, 30);
std::uniform_int_distribution<int> range2(1, 7);

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

ofstream freport;

void Coords(int x, int y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(hStdOut, coord);
}

void MyCard::begin()
{
    system("color 03");
    int choice = 1, count, control;
    Coords(27, 12);
    cout << "\t\t\t--> Entrance <--";
    Coords(24, 13);
    cout << "\t\t\t\b       Exit    ";
    count = 1;
    while (count == 1) {
        control = _getch();
        if (control == 224 || control == 0)
        {
            control = _getch();
        }
        if (control == 80)
        {
            choice *= -1;
            if (choice == 1)
            {
                Coords(27, 12);
                cout << "\t\t\t--> Entrance <--";
                Coords(24, 13);
                cout << "\t\t\t\b       Exit    ";
            }
            else
            {
                Coords(27, 12);
                cout << "\t\t\t    Entrance    ";
                Coords(24, 13);
                cout << "\t\t\t\b   --> Exit <--";
            }
        }
        else if (control == 72)
        {
            choice *= -1;
            if (choice == 1)
            {
                Coords(27, 12);
                cout << "\t\t\t--> Entrance <--";
                Coords(24, 13);
                cout << "\t\t\t\b       Exit    ";
            }
            else
            {
                Coords(27, 12);
                cout << "\t\t\t    Entrance   ";
                Coords(24, 13);
                cout << "\t\t\t\b   --> Exit <--";
            }
        }
        else if (control == 13)
        {
            count = 0;
        }
        cout << '\n' << '\n' << '\n' << '\n' << '\n';
    }
    while (count == 1);
    {
        if (choice != 1)
        {
            exit(0);
        }
    }
    system("cls");
}

int Time::getDates()
{
    return dates;
}

void Time::setDates(int day, int month, int year)
{
    if (day > 0 && day <= 31)
    {
        dates = day;
    }
    else if (month > 0 && month <= 12)
    {
        dates = month;
    }
    else if (year > 1940 && year <= 2023)
    {
        dates = year;
    }
}

int Registration::getAge()
{
    return age;
}

int Registration::getContacteNumber()
{
    return contactNumber;
}

void Registration::setAge(int value)
{
    if (value > 17 && value < 91)
    {
        age = value;
    }
    else
    {
        cout << "You entered an invalid age." << '\n';
        age = 0;
        exit(1);
    }
}

void Registration::setContactNumber(int value)
{
    if (value > 111111111 && value < 999999999)
    {
        contactNumber = value;
    }
    else
    {
        cout << "You entered an invalid number." << '\n';
        contactNumber = 0;
        exit(1);
    }
}

void Registration::personInput()
{
    int age;
    int contactNum;
    Registration per;
    Registration person(per.firstName, per.lastName);
    cout << "Enter first name: ";
    cin >> person.firstName;
    cout << "Enter last name: ";
    cin >> person.lastName;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter contact number: +994";
    cin >> contactNum;

    setAge(age);
    setContactNumber(contactNum);

    cout << '\n';
    cout << "The card is registered in the name of: " << person << '\n';
    cout << "Age: " << getAge() << '\n';
    cout << "Contact number: +994" << getContacteNumber() << '\n';
}

void Registration::example()
{
    cout << "You must be 18 years of age or older to registe." << '\n' << '\n';
    cout << "Example: " << '\n' << '\n';
    cout << "--------------------------------------" << '\n';
    cout << "First name: " << "Andrey" << '\n';
    cout << "Last name: " << "Ivanov" << '\n';
    cout << "Age: " << 19 << '\n';
    cout << "Contact number: +994" << 703415643 << '\n';
    cout << "--------------------------------------" << '\n' << '\n';
}

void Time::datesInput()
{
    Time time;
    time.setDates(range1(engine), 0, 0);
    cout << time.getDates() << '.';
    freport << time.getDates() << '.';
    time.setDates(0, range2(engine), 0);
    cout << time.getDates() << '.';
    freport << time.getDates() << '.';
    time.setDates(0, 0, 2023);
    cout << time.getDates() << ' ';
    freport << time.getDates() << ' ';
}

void DebitOrders::topUpBalance()
{
    fbalance.open("MyCard (debit) balance.txt", ios::app);
    cout << "Enter amount: ";
    cin >> balance_;
    if (balance_ < 0)
    {
        balance_ = 0;
    }
    balance += balance_;
    fbalance << "Balance: " << balance << " USD" << '\n';
    cout << '\n';
    fbalance.close();
}

void DebitOrders::viewBalance()
{
    cout << "Balance: " << balance << '\n' << '\n';
}

void DebitOrders::withdrawBalance()
{
    if (balance_ <= 0)
    {
        balance_ = 0;
    }
    cout << "Enter withdrawal amount (commission 0%) : ";
    cin >> balance_;
    if (balance_ > balance)
    {
        balance_ = 0;
    }   
    balance -= balance_;   
}

void DebitOrders::spendMoney()
{
    cout << "4.1 " << "Groceries and supermarkets" << '\n';
    cout << "4.2 " << "Entertainment and sports" << '\n';
    cout << "4.3 " << "Clothing and footwear" << '\n';
    cout << "Write: ";
    cin >> choice3;
    if (choice3 == 4.1)
    {
        balance1 = balance_;
        cout << "Enter amount:";
        cin >> balance1;
        if (balance1 > balance)
        {
            balance1 = 0;
            cout << "You don't have much money." << '\n' << '\n';
        }
        else
        {
        balance -= balance1;
        cout << "You spent money on groceries and supermarkets category!" << '\n';
        }

    }
    if (choice3 == 4.2)
    {
        balance2 = balance_;
        cout << "Enter amount:";
        cin >> balance2;
        if (balance2 > balance)
        {
            balance2 = 0;
            cout << "You don't have much money." << '\n' << '\n';
        }
        else
        {
            balance -= balance2;
            cout << "You spent money on entertainment and sports category!" << '\n';
        }
    }

    if (choice3 == 4.3)
    {
        balance3 = balance_;
        cout << "Enter amount:";
        cin >> balance3;
        if (balance3 > balance)
        {
            balance3 = 0;
            cout << "You don't have much money." << '\n' << '\n';
        }
        else
        {
            balance -= balance3;
            cout << "You spent money on the clothing and footwear category!" << '\n';
        }
    }
}

void DebitOrders::viewReport()
{
    freport.open("MyCard (debit) Report.txt", ios::app | ios::binary);
    cout << "Groceries and supermarkets -> " << balance1 << ' ';
    freport << "Groceries and supermarkets -> " << balance1 << ' ';
    if (balance1 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Entertainment and sports -> " << balance2 << ' ';
    freport << "Entertainment and sports -> " << balance2 << ' ';
    if (balance2 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Clothing and footwear -> " << balance3 << ' ';
    freport << "Clothing and footwear -> " << balance3 << ' ';
    if (balance3 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    freport.close();
}

void DebitOrders::topCategories()
{
    ftops.open("MyCard (debit) Top's.txt", ios::app | ios::binary);
    cout << "Top costs by category: " << '\n';
    ftops << "Top costs by category: " << '\n';
    if (balance1 > balance2 && balance1 > balance3)
    {
        cout << "Groceries and supermarkets -> " << balance1 << '\n';
        ftops << "Groceries and supermarkets -> " << balance1 << '\n';
    }
    if (balance2 > balance1 && balance2 > balance3)
    {
        cout << "Entertainment and sports -> " << balance2 << '\n';
        ftops << "Entertainment and sports -> " << balance2 << '\n';
    }
    if (balance3 > balance1 && balance3 > balance2)
    {
        cout << "Clothing and footwear -> " << balance3 << '\n';
        ftops << "Clothing and footwear -> " << balance3 << '\n';
    }
    if (balance1 == balance2 && balance1 == balance3
        || balance2 == balance1 && balance2 == balance3
        || balance3 == balance1 && balance3 == balance2)
    {
        cout << "In all categories the same amount of costs" << '\n';
        ftops << "In all categories the same amount of costs" << '\n';
    }
    ftops.close();
}

void CreditOrders::topUpBalance()
{
    fbalance.open("MyCard (credit) balance.txt", ios::app);
    cout << "Enter amount: ";
    cin >> balance_;
    if (balance_ < 0)
    {
        balance_ = 0;
    }
    balance += balance_ - 200;
    fbalance << "Balance: " << balance << " USD" << '\n';
    cout << '\n';
    fbalance.close();
}

void CreditOrders::viewBalance()
{
    cout << "Balance (commission 2%): " << balance << '\n' << '\n';
}

void CreditOrders::withdrawBalance()
{
    if (balance_ <= 0)
    {
        balance_ = 0;
    }

    cout << "Enter withdrawal amount: ";
    cin >> balance_;
    if (balance_ > balance)
    {
        balance_ = 0;
    }
    balance -= balance_;
}

void CreditOrders::spendMoney()
{
    cout << "4.1 Groceries and supermarkets" << '\n';
    cout << "4.2 Entertainment and sports" << '\n';
    cout << "4.3 Clothing and footwear" << '\n';
    cout << "Write: ";
    cin >> choice3;
    if (choice3 == 4.1)
    {
        balance1 = balance_;
        cout << "Enter amount:";
        cin >> balance1;
        if (balance1 > balance)
        {
            balance1 = 0;
            cout << "You don't have much money." << '\n' << '\n';
        }
        else
        {
            balance -= balance1;
            cout << "You spent money on groceries and supermarkets category!" << '\n';
        }

    }
    if (choice3 == 4.2)
    {
        balance2 = balance_;
        cout << "Enter amount:";
        cin >> balance2;
        if (balance2 > balance)
        {
            balance2 = 0;
            cout << "You don't have much money." << '\n' << '\n';
        }
        else
        {
            balance -= balance2;
            cout << "You spent money on entertainment and sports category!" << '\n';
        }
    }

    if (choice3 == 4.3)
    {
        balance3 = balance_;
        cout << "Enter amount:";
        cin >> balance3;
        if (balance3 > balance)
        {
            balance3 = 0;
            cout << "You don't have much money." << '\n' << '\n';
        }
        else
        {
            balance -= balance3;
            cout << "You spent money on the clothing and footwear category!" << '\n';
        }
    }
}

void CreditOrders::viewReport()
{
    freport.open("MyCard (credit) Report.txt", ios::app | ios::binary);
    cout << "Groceries and supermarkets -> " << balance1 << ' ';
    freport << "Groceries and supermarkets -> " << balance1 << ' ';
    if (balance1 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Entertainment and sports -> " << balance2 << ' ';
    freport << "Entertainment and sports -> " << balance2 << ' ';
    if (balance2 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Clothing and footwear -> " << balance3 << ' ';
    freport << "Clothing and footwear -> " << balance3 << ' ';
    if (balance3 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    freport.close();
}

void CreditOrders::topCategories()
{
    ftops.open("MyCard (credit) Top's.txt", ios::app | ios::binary);
    cout << "Top costs by category: " << '\n';
    ftops << "Top costs by category: " << '\n';
    if (balance1 > balance2 && balance1 > balance3)
    {
        cout << "Groceries and supermarkets -> " << balance1 << '\n';
        ftops << "Groceries and supermarkets -> " << balance1 << '\n';
    }
    if (balance2 > balance1 && balance2 > balance3)
    {
        cout << "Entertainment and sports -> " << balance2 << '\n';
        ftops << "Entertainment and sports -> " << balance2 << '\n';
    }
    if (balance3 > balance1 && balance3 > balance2)
    {
        cout << "Clothing and footwear -> " << balance3 << '\n';
        ftops << "Clothing and footwear -> " << balance3 << '\n';
    }
    if (balance1 == balance2 && balance1 == balance3
        || balance2 == balance1 && balance2 == balance3
        || balance3 == balance1 && balance3 == balance2)
    {
        cout << "In all categories the same amount of costs" << '\n';
        ftops << "In all categories the same amount of costs" << '\n';
    }
    ftops.close();
}

void LeoCredCard::topUpBalance()
{
    fbalance.open("Leobank balance.txt", ios::app);
    cout << "Enter amount: ";
    cin >> balance_;
    if (balance_ < 0)
    {
        balance_ = 0;
    }
    balance += balance_ - 200;
    fbalance << "Balance: " << balance << " USD" << '\n';
    cout << '\n';
    fbalance.close();
}

void LeoCredCard::topCategories()
{
    ftops.open("Leobank Top's.txt", ios::app | ios::binary);
    cout << "Top costs by category: " << '\n';
    ftops << "Top costs by category: " << '\n';
    if (balance1 > balance2 && balance1 > balance3)
    {
        cout << "Groceries and supermarkets -> " << balance1 << '\n';
        ftops << "Groceries and supermarkets -> " << balance1 << '\n';
    }
    if (balance2 > balance1 && balance2 > balance3)
    {
        cout << "Entertainment and sports -> " << balance2 << '\n';
        ftops << "Entertainment and sports -> " << balance2 << '\n';
    }
    if (balance3 > balance1 && balance3 > balance2)
    {
        cout << "Clothing and footwear -> " << balance3 << '\n';
        ftops << "Clothing and footwear -> " << balance3 << '\n';
    }
    if (balance1 == balance2 && balance1 == balance3
        || balance2 == balance1 && balance2 == balance3
        || balance3 == balance1 && balance3 == balance2)
    {
        cout << "In all categories the same amount of costs" << '\n';
        ftops << "In all categories the same amount of costs" << '\n';
    }
    ftops.close();
}

void LeoCredCard::viewReport()
{
    freport.open("Leobank Report.txt", ios::app | ios::binary);
    cout << "Groceries and supermarkets -> " << balance1 << ' ';
    freport << "Groceries and supermarkets -> " << balance1 << ' ';
    if (balance1 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Entertainment and sports -> " << balance2 << ' ';
    freport << "Entertainment and sports -> " << balance2 << ' ';
    if (balance2 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Clothing and footwear -> " << balance3 << ' ';
    freport << "Clothing and footwear -> " << balance3 << ' ';
    if (balance3 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    freport.close();
}

void UDebCard::topUpBalance()
{
    fbalance.open("Ubank balance.txt", ios::app);
    cout << "Enter amount: ";
    cin >> balance_;
    if (balance_ < 0)
    {
        balance_ = 0;
    }
    balance += balance_;
    fbalance << "Balance: " << balance << " USD" << '\n';
    cout << '\n';
    fbalance.close();
}

void UDebCard::topCategories()
{
    ftops.open("Ubank Top's.txt", ios::app | ios::binary);
    cout << "Top costs by category: " << '\n';
    ftops << "Top costs by category: " << '\n';
    if (balance1 > balance2 && balance1 > balance3)
    {
        cout << "Groceries and supermarkets -> " << balance1 << '\n';
        ftops << "Groceries and supermarkets -> " << balance1 << '\n';
    }
    if (balance2 > balance1 && balance2 > balance3)
    {
        cout << "Entertainment and sports -> " << balance2 << '\n';
        ftops << "Entertainment and sports -> " << balance2 << '\n';
    }
    if (balance3 > balance1 && balance3 > balance2)
    {
        cout << "Clothing and footwear -> " << balance3 << '\n';
        ftops << "Clothing and footwear -> " << balance3 << '\n';
    }
    if (balance1 == balance2 && balance1 == balance3
        || balance2 == balance1 && balance2 == balance3
        || balance3 == balance1 && balance3 == balance2)
    {
        cout << "In all categories the same amount of costs" << '\n';
        ftops << "In all categories the same amount of costs" << '\n';
    }
    ftops.close();
}

void UDebCard::viewReport()
{
    freport.open("Ubank Report.txt", ios::app | ios::binary);
    cout << "Groceries and supermarkets -> " << balance1 << ' ';
    freport << "Groceries and supermarkets -> " << balance1 << ' ';
    if (balance1 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Entertainment and sports -> " << balance2 << ' ';
    freport << "Entertainment and sports -> " << balance2 << ' ';
    if (balance2 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    cout << "Clothing and footwear -> " << balance3 << ' ';
    freport << "Clothing and footwear -> " << balance3 << ' ';
    if (balance3 == 0)
    {
        cout << "You didn't buy anything";
        freport << "You didn't buy anything";
    }
    else
    {
        cout << "  Time:  ";
        freport << "  Time:  ";
        time.datesInput();
    }
    cout << '\n';
    freport << '\n';
    freport.close();
}

void MyCard::createCard()
{
    cout << "1. Create a debit card. " << '\n';
    cout << "2. Create a credit card." << '\n';

    secondDigitsOfTheCard = range(engine);
}

void MyCard::menu()
{
    DebitOrders deborders;
    CreditOrders credorders;
    cin >> choice;
    if (choice == 1)
    {
        person.example();
        person.personInput();
        firsDigitsOfTheCard = 40935066;
        cout << '\n';
        cout << "\t\t\t\tWelcome to Applications MyCard!!!" << '\n';
        cout << "\t\t\t\tYou have registered a debit card!" << '\n' << '\n' << '\n';
        cout << "Your card: " << firsDigitsOfTheCard << ' ' << secondDigitsOfTheCard << '\n' << '\n';

        cout << "MENU" << '\n';
        cout << "1. Top up balance" << '\n';
        cout << "2. View balance" << '\n';
        cout << "3. Withdraw balance" << '\n';
        cout << "4. Spend money" << '\n';
        cout << "5. View report" << '\n';
        cout << "6. View top costs by categories" << '\n';
        cout << "7. Exit" << '\n';
        while (true)
        {
            cout << "Enter the number: ";
            cin >> choice2;
            if (choice2 == 1)
            {
                deborders.topUpBalance();
            }
            if (choice2 == 2)
            {
                deborders.viewBalance();
            }
            if (choice2 == 3)
            {
                deborders.withdrawBalance();
            }
            if (choice2 == 4)
            {
                deborders.spendMoney();
            }
            if (choice2 == 5)
            {
                deborders.viewReport();
            }
            if (choice2 == 6)
            {
                deborders.topCategories();
            }
            if (choice2 == 7)
            {
                break;
            }
        }
    }
    if (choice == 2)
    {
        person.example();
        person.personInput();
        firsDigitsOfTheCard = 40935067;
        cout << '\n';
        cout << "\t\t\t\tWelcome to Applications MyCard!!!" << '\n';
        cout << "\t\t\t\tYou have registered a credit card!" << '\n' << '\n' << '\n';
        cout << "Your card: " << firsDigitsOfTheCard << ' ' << secondDigitsOfTheCard << '\n' << '\n';

        cout << "MENU" << '\n';
        cout << "1. Top up balance" << '\n';
        cout << "2. View balance" << '\n';
        cout << "3. Withdraw balance" << '\n';
        cout << "4. Spend money" << '\n';
        cout << "5. View report" << '\n';
        cout << "6. View top costs by categories" << '\n';
        cout << "7. Exit" << '\n';
        while (true)
        {
            cout << "Enter the number: ";
            cin >> choice2;
            if (choice2 == 1)
            {
                credorders.topUpBalance();
            }
            if (choice2 == 2)
            {
                credorders.viewBalance();
            }
            if (choice2 == 3)
            {
                credorders.withdrawBalance();
            }
            if (choice2 == 4)
            {
                credorders.spendMoney();
            }
            if (choice2 == 5)
            {
                credorders.viewReport();
            }
            if (choice2 == 6)
            {
                credorders.topCategories();
            }
            if (choice2 == 7)
            {
                break;
            }
        }
    }
    else
    {
        exit(1);
    }
}

void LeoBank::createCard()
{
    cout << "1. Create a credit card." << '\n';
    secondDigitsOfTheCard = range(engine);
}

void LeoBank::menu()
{
    LeoCredCard lcredorders;
    cin >> choice;
    if (choice == 1)
    {
        person.example();
        person.personInput();
        firsDigitsOfTheCard = 40985844;
        cout << '\n';
        cout << "\t\t\t\tWelcome to Applications LeoBank!!!" << '\n';
        cout << "\t\t\t\tYou have registered a credit card!" << '\n' << '\n' << '\n';
        cout << "Your card: " << firsDigitsOfTheCard << ' ' << secondDigitsOfTheCard << '\n' << '\n';

        cout << "MENU" << '\n';
        cout << "1. Top up balance" << '\n';
        cout << "2. View balance" << '\n';
        cout << "3. Withdraw balance" << '\n';
        cout << "4. Spend money" << '\n';
        cout << "5. View report" << '\n';
        cout << "6. View top costs by categories" << '\n';
        cout << "7. Exit" << '\n';
        while (true)
        {
            cout << "Enter the number: ";
            cin >> choice2;
            if (choice2 == 1)
            {
                lcredorders.topUpBalance();
            }
            if (choice2 == 2)
            {
                lcredorders.viewBalance();
            }
            if (choice2 == 3)
            {
                lcredorders.withdrawBalance();
            }
            if (choice2 == 4)
            {
                lcredorders.spendMoney();
            }
            if (choice2 == 5)
            {
                lcredorders.viewReport();
            }
            if (choice2 == 6)
            {
                lcredorders.topCategories();
            }
            if (choice2 == 7)
            {
                break;
            }
        }
    }
    else
    {
        exit(1);
    }
}

void Ubank::createCard()
{
    cout << "1. Create a debit card. " << '\n';

    secondDigitsOfTheCard = range(engine);
}

void Ubank::menu()
{
    UDebCard udeborders;
    cin >> choice;

    if (choice == 1)
    {
        person.example();
        person.personInput();
        firsDigitsOfTheCard = 40281355;
        cout << '\n';
        cout << "\t\t\t\tWelcome to Applications Ubank!!!" << '\n';
        cout << "\t\t\t\tYou have registered a debit card!" << '\n' << '\n' << '\n';
        cout << "Your card: " << firsDigitsOfTheCard << ' ' << secondDigitsOfTheCard << '\n' << '\n';

        cout << "MENU" << '\n';
        cout << "1. Top up balance" << '\n';
        cout << "2. View balance" << '\n';
        cout << "3. Withdraw balance" << '\n';
        cout << "4. Spend money" << '\n';
        cout << "5. View report" << '\n';
        cout << "6. View top costs by categories" << '\n';
        cout << "7. Exit" << '\n';
        while (true)
        {
            cout << "Enter the number: ";
            cin >> choice2;
            if (choice2 == 1)
            {
                udeborders.topUpBalance();
            }
            if (choice2 == 2)
            {
                udeborders.viewBalance();
            }
            if (choice2 == 3)
            {
                udeborders.withdrawBalance();
            }
            if (choice2 == 4)
            {
                udeborders.spendMoney();
            }
            if (choice2 == 5)
            {
                udeborders.viewReport();
            }
            if (choice2 == 6)
            {
                udeborders.topCategories();
            }
            if (choice2 == 7)
            {
                break;
            }
        }
    }
}

void Bank::createCard(MyCard* card)
{
    card->createCard();
}

void Bank::menu(MyCard* card)
{
    card->menu();
}

void run()
{
    short choice;
    MyCard mycard;
    LeoBank leo;
    Ubank unibank;
    Bank pcard;
    mycard.begin();

    cout << "WELCOME TO THE BANK!" << '\n';
    cout << "CARDS: " << '\n';
    cout << "1. MyCard " << ' ';
    cout << "2. LeoBakn " << ' ';
    cout << "3. Ubank " << '\n';

    cin >> choice;
    cout << '\n';

    if (choice == 1)
    {
        pcard.createCard(&mycard);
        pcard.menu(&mycard);
    }
    if (choice == 2)
    {
        pcard.createCard(&leo);
        pcard.menu(&leo);
    }
    if (choice == 3)
    {
        pcard.createCard(&unibank);
        pcard.menu(&unibank);
    }
}