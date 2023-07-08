#include "Map.h" // suctome hederfile for class Map, also std and iostream incuded
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <random>

const int MAX = 30; // maximum length of the password
const int MIN = 20; // minimum length of the password

// input validation
long long int input(int min, long long int max)
{
    string n;

    while (true)
    {
        cin >> n;

        for (int i = 0; isdigit(n[i]); i++)
        {
            if (i == n.size() - 1)
            {
                long long int num = stoll(n);
                if (num >= min && num <= max)
                    return num;
            }
        }

        cout << "Invalid Input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Type Again : ";
    }
}

class PassWord
{
private:
    string loginPass; // password for login to the software
    Map arr;          // data structure for saving the passwords

    // generating more precise random number between MAX and MIN
    int random(int max, int min)
    {
        static unsigned long long n = 1;
        srand(time(nullptr) * n * getpid());
        n++;
        int val = (rand() % (max - min + 1)) + min;

        return val;
    }
    int random()
    {
        static unsigned long long n = 1;
        srand(time(nullptr));
        n++;
        return rand();
    }

public:
    PassWord(const string &loginPass)
    {
        this->loginPass = loginPass;
    }
    // adding the password to the hash map
    void add(const string &key, const string &pass)
    {
        if (!arr.find(key))
        {
            arr[key] = pass;
        }
        else // asking to overwrite the password
        {
            cout << "The Password already exits!" << endl
                 << "Do you want to overwrite the password?(y,n) : ";
            string choice;
            while (true)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                getline(cin, choice);
                if (choice.size() == 1 && (tolower(choice[0]) == 'y' || tolower(choice[0]) == 'n'))
                {
                    break;
                }
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Type Again : ";
            }
            if (tolower(choice[0]) == 'y')
            {
                arr[key] = pass; // overwriting the password
            }
        }
    }

    // deleting the saved password
    void delete_pass(const string &key)
    {
        if (!this->arr.delete_node(key))
        {
            cout << "The password was not found!" << endl;
        }
    }
    // printing the saved password
    void print()
    {
        bool flag = true;

        if (!arr.empty())
        {
            arr.print();
            flag = false;
        }
        if (!arr.list.empty())
        {
            arr.list.print();
            flag = false;
        }

        if (flag)
        {
            cout << "No password has been saved!" << endl;
        }
    }
    // generating random password
    string generate_random_pass()
    {
        // all the possible characters for inserting in the password
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
        string password;
        int len = random(MAX, MIN);

        for (auto i = 0; i < len; i++)
        {
            int randIndex = random() % characters.size();
            password += characters[randIndex];
        }
        cout << password.length() << endl;

        return password;
    }
    // string to map converter
    Map string_to_map()
    {

    }
    // string to map converter
    string map_to_string()
    {

    }
};
// encrypting all the data of the map
string encrypt(const string &data)
{
}
// decrypting all the data from the file
string decrypt(const string &data)
{
}

int main()
{
    string loginPass = "24234";
    // cout << "\nType the password to login to the Password Manager.\n-> ";
    // cin >> loginPass;

    PassWord passWord(loginPass);

    string name = "akash";
    string pass = passWord.generate_random_pass();

    passWord.add(name, pass);
    passWord.print();
    passWord.delete_pass(name);
    passWord.print();

    return 0;
}