#include <bits/stdc++.h>
#include <fstream>
#include <ctype.h>
#include <iostream>

using namespace std;
ofstream fout("token.txt");

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;

    LinkedList()
    {
        head = nullptr;
    }

    void add(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data;
            if (temp->next)
                cout << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool find(const T &value)
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    int flag = 0;

    for (int i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

template <typename U>
int lengthOfList(LinkedList<U> &list)
{
    Node<U> *temp = list.head;
    int length = 0;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

template <typename T>
void printUniqueOccurrences(LinkedList<T> &list)
{
    Node<T> *current = list.head;
    unordered_set<T> visited;
    cout << endl;

    while (current)
    {
        T value = current->data;
        int count = 1;

        if (visited.find(value) == visited.end())
        {
            visited.insert(value);

            Node<T> *temp = current->next;
            while (temp)
            {
                if (temp->data == value)
                    count++;
                temp = temp->next;
            }

            if (count >= 1)
            {
                fout << value << " occurs " << count << " time(s)" << endl;
            }
        }

        current = current->next;
    }
}

void checkKeywordsAndSemicolon(const string &line, LinkedList<string> &initializedIdentifiers, int &linecount, ofstream &errorFile)
{
    istringstream iss(line);
    string word;
    bool keywordFound = false;
    bool semicolonFound = false;

    if (!line.empty())
    {
        linecount++;
    }

    while (iss >> word)
    {
        if (line.empty() || line.find_first_not_of(" \t") == string::npos)
        {
            return;
        }

        if (word == "{" || word == "}" || word == " ")
        {
            return;
        }

        if (!word.empty() && isKeyword(&word[0]))
        {

            size_t lastPos = line.find_last_not_of(" \t\r\n");
            if (lastPos != string::npos && line[lastPos] == ';')
            {

                keywordFound = true;
                return;
            }
            else if (line.find("if") != string::npos || line.find("else") != string::npos ||
                     line.find("while") != string::npos || line.find("while") != string::npos)
            {

                keywordFound = true;
                return;
            }
        }

        if (initializedIdentifiers.find(word))
        {
            return;
        }

        if (word.find(';') != string::npos)
        {
            semicolonFound = true;
        }
    }

    if (!keywordFound && !semicolonFound && !line.empty())
    {

        errorFile << "Line: " << linecount << " - Error " << line << endl;
    }
}

void readAndCheckKeywordsWithSemicolon(const string &filename)
{
    ifstream fin(filename);
    string line;
    LinkedList<string> initializedIdentifiers;
    int linecount = 0;

    if (!fin.is_open())
    {
        cout << "Error while opening the file\n";
        return;
    }

    ofstream errorFile("error.txt");
    if (!errorFile.is_open())
    {
        cout << "Error while creating the error file\n";
        return;
    }

    while (getline(fin, line))
    {
        checkKeywordsAndSemicolon(line, initializedIdentifiers, linecount, errorFile);
    }

    fin.close();
    errorFile.close();
}

int main()
{
    char ch, buffer[15], b[30] = {0};
    char logical_op[] = "><";
    char math_op[] = "+-*/=";
    char other[] = ",;\(){}[]'':";
    ifstream fin("SourceCode.txt");
    int mark[1000] = {0};
    int j = 0, kc = 0, ic = 0, lc = 0, mc = 0, nc = 0, oc = 0, aaa = 0;
    int kco = 0, ico = 0, lco = 0, mco = 0, nco = 0, oco = 0;
    int lineNumber = 1;

    LinkedList<string> k;
    LinkedList<string> id;
    LinkedList<char> lo;
    LinkedList<char> ma;
    LinkedList<string> nu;
    LinkedList<char> ot;

    LinkedList<string> ko;
    LinkedList<string> ido;
    LinkedList<char> loo;
    LinkedList<char> mao;
    LinkedList<string> nuo;
    LinkedList<char> oto;
    if (!fin.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }

    while (!fin.eof())
    {
        ch = fin.get();

        for (int i = 0; i < 12; ++i)
        {
            if (ch == other[i])
            {
                int aa = ch;
                oto.add(ch);
                if (mark[aa] != 1)
                {
                    ot.add(ch);
                    mark[aa] = 1;
                    ++oc;
                }
            }
        }

        for (int i = 0; i < 5; ++i)
        {
            if (ch == math_op[i])
            {
                int aa = ch;
                mao.add(ch);
                if (mark[aa] != 1)
                {
                    ma.add(ch);
                    mark[aa] = 1;
                    ++mc;
                }
            }
        }

        for (int i = 0; i < 2; ++i)
        {
            if (ch == logical_op[i])
            {
                int aa = ch;
                loo.add(ch);
                if (mark[aa] != 1)
                {
                    lo.add(ch);
                    mark[aa] = 1;
                    ++lc;
                }
            }
        }

        if (isdigit(ch) || ch == '.')
        {
            b[aaa++] = ch;
        }

        if ((ch == ' ' || ch == '\n' || ch == ';' || fin.eof()) && aaa != 0)
        {
            b[aaa] = '\0';
            aaa = 0;
            string num(b);
            bool isPresent = false;
            Node<string> *temp = nu.head;
            while (temp)
            {
                if (temp->data == num)
                {
                    isPresent = true;
                    break;
                }
                temp = temp->next;
            }
            nuo.add(num);
            if (!isPresent)
            {
                nu.add(num);
                ++nc;
            }
        }
        if (isalpha(ch) || ch == '_')
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n' || ch == ';' || fin.eof() || ch == ',') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;

            string word(buffer);

            if (isKeyword(buffer))
            {
                bool isPresent = false;
                Node<string> *temp = k.head;

                while (temp)
                {
                    if (temp->data == word)
                    {
                        isPresent = true;
                        break;
                    }
                    temp = temp->next;
                }

                ko.add(word);

                if (!isPresent)
                {
                    k.add(word);
                    ++kc;
                }
            }
            else
            {
                istringstream iss(word);
                string identifier;
                while (getline(iss, identifier, ','))
                {
                    if (!identifier.empty())
                    {
                        bool isPresent = false;
                        Node<string> *temp = id.head;

                        while (temp)
                        {
                            if (temp->data == identifier)
                            {
                                isPresent = true;
                                break;
                            }
                            temp = temp->next;
                        }

                        ido.add(identifier);

                        if (!isPresent)
                        {
                            id.add(identifier);
                            ++ic;
                        }
                    }
                }
            }
        }
        if (ch == '\n')
            lineNumber++;
    }

    fin.close();

    cout << "Program Ended\n";

    if (!fout.is_open())
    {
        cout << "Error opening output file.\n";
        exit(0);
    }
    fout << "Keywords: ";
    Node<string> *keywordNode = k.head;
    while (keywordNode)
    {
        fout << keywordNode->data;
        if (keywordNode->next)
            fout << " ";
        keywordNode = keywordNode->next;
    }
    fout << endl;

    fout << "Identifiers: ";
    Node<string> *identifierNode = id.head;
    while (identifierNode)
    {
        fout << identifierNode->data;
        if (identifierNode->next)
            fout << " ";
        identifierNode = identifierNode->next;
    }
    fout << endl;

    fout << "Math Operators: ";
    Node<char> *mathOpNode = ma.head;
    while (mathOpNode)
    {
        fout << mathOpNode->data;
        if (mathOpNode->next)
            fout << " ";
        mathOpNode = mathOpNode->next;
    }
    fout << endl;

    fout << "Logical Operators: ";
    Node<char> *logicalOpNode = lo.head;
    while (logicalOpNode)
    {
        fout << logicalOpNode->data;
        if (logicalOpNode->next)
            fout << " ";
        logicalOpNode = logicalOpNode->next;
    }
    fout << endl;

    fout << "Numerical Values: ";
    Node<string> *numNode = nu.head;
    while (numNode)
    {
        fout << numNode->data;
        if (numNode->next)
            fout << " ";
        numNode = numNode->next;
    }
    fout << endl;

    fout << "Others: ";
    Node<char> *otherNode = ot.head;
    while (otherNode)
    {
        fout << otherNode->data;
        if (otherNode->next)
            fout << " ";
        otherNode = otherNode->next;
    }
    fout << endl
         << endl;
    fout << "\nKeywords and their occurrences:" << endl;
    printUniqueOccurrences<string>(ko);

    fout << "\nIdentifiers and their occurrences:" << endl;
    printUniqueOccurrences<string>(ido);

    fout << "\nMath Operators and their occurrences:" << endl;
    printUniqueOccurrences<char>(mao);

    fout << "\nLogical Operators and their occurrences:" << endl;
    printUniqueOccurrences<char>(loo);

    fout << "\nNumerical Values and their occurrences:" << endl;
    printUniqueOccurrences<string>(nuo);

    fout << "\nOther Characters and their occurrences:" << endl;
    printUniqueOccurrences<char>(oto);

    int keywordsLength = lengthOfList(ko);
    fout << "\nLength of keywords list: " << keywordsLength << endl;

    int IdentifierLength = lengthOfList(ido);
    fout << "Length of Identifier list: " << IdentifierLength << endl;

    int LogicOperatorsLength = lengthOfList(loo);
    fout << "Length of Logic list: " << LogicOperatorsLength << endl;

    int NumericalLength = lengthOfList(nuo);
    fout << "Length of Numerical list: " << NumericalLength << endl;

    int mathOperatorsLength = lengthOfList(mao);
    fout << "Length of math operators list: " << mathOperatorsLength << endl;

    int othersLength = lengthOfList(oto);
    fout << "Length of other characters list: " << othersLength << endl;

    fout.close();
    readAndCheckKeywordsWithSemicolon("SourceCode.txt");
    return 0;
}