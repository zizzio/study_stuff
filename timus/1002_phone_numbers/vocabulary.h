
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

struct vocabulary
{
    struct node
    {
        node(unsigned l)
            :leaf(l)
        {
        }

        ~node()
        {
            for(auto i = 0; i < words.size(); ++i)
                delete words[i];
        }
        vector<node*> words;
        unsigned leaf;
    };

    bool is_eq (int i) {
        return ((i%2)==1);
    }

    void add_letter(node* root, unsigned word, unsigned place)
    {
        auto &words = root->words;
        auto it = find_if (words.begin(), words.end(), word);  
        if(it == words.end())
        {
            words.push_back(new node(word));
        }
        
    }

unsigned get_num(char c)
{
    switch (c)
    {
    case 'i':
    case 'j':
        return 1;
    case 'a':
    case 'b':
    case 'c':
        return 2;
    case 'd':
    case 'e':
    case 'f':
        return 3;
    case 'g':
    case 'h':
        return 4;
    case 'k':
    case 'l':
        return 5;
    case 'm':
    case 'n':
        return 6;
    case 'p':
    case 'r':
    case 's':
        return 7;
    case 't':
    case 'u':
    case 'v':
        return 8;
    case 'w':
    case 'x':
    case 'y':
        return 9;
    case 'o':
    case 'q':
    case 'z':
        return 0;
    default:
        assert(0);
        return -1;
    }
}

void add_word(string new_word)
{
    words_.push_back(new_word);
    for (int i = 0, int len = new_word.size(); i < len; ++i)
    {
        index[get_num(new_word[i])]
    }
}

add_letter()

private:
    vector<string> words_;
    node*[10] index;
};