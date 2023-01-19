//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#include "Gatcha_Machine.h"


string themes[8] = { "None", "Dragon_ball_z", "Naruto","Pokemon","Attack_on_titan","Bleach","SpyXFamily","Full_metal_alchemist" };

Gatcha_machine::Gatcha_machine(Series theme, const string& color, int cost) : m_theme(theme), m_capsule_cost(cost), Extra_capsules(NULL),
                                                         c_size(0), ec_size(0),Shell_color(color) {
    memset(capsules, NULL, 10 * sizeof(Capsule *));

}


Capsule *Gatcha_machine::Roll_for_capsule(int num) {

    if (!c_size)
        return NULL;

    while (capsules[num] == NULL || num >= c_size) {
        num = rand() % 10;
    }
    Capsule *random = capsules[num];
    capsules[num] = NULL;

    if (ec_size != 0) {
        capsules[num] = Extra_capsules[ec_size - 1];
        Capsule** new_extra = new Capsule * [ec_size - 1];
        memcpy(new_extra, Extra_capsules, ec_size - 1);
        delete[] Extra_capsules;
        Extra_capsules = new_extra;
        ec_size--;
        return random;
    }
    
    
        if (capsules[num] == NULL ) {
            for (int j = num; j < c_size; j++) {
                capsules[j] = capsules[j + 1];
            }
        }
    
    c_size--;

    
    
    return random;


}

void Gatcha_machine::insert_extra(Capsule *capsule) {
    Candy *candy = dynamic_cast<Candy *>(capsule);
    Toy *toy = dynamic_cast<Toy *>(capsule);


    if (!ec_size) {
        Extra_capsules = new Capsule *;
        if (candy)
            *Extra_capsules = new Candy(*candy);
        else *Extra_capsules = new Toy(*toy);

        ec_size++;
        return;
    }
    Capsule **newlist = new Capsule *[ec_size + 1];
    memcpy(newlist, Extra_capsules, ec_size);
    delete Extra_capsules;
    Extra_capsules = newlist;
    if (candy)
        Extra_capsules[ec_size] = new Candy(*candy);
    else Extra_capsules[ec_size] = new Toy(*toy);
    ec_size++;
    return;
}


bool Gatcha_machine::insert_capsule(Capsule *capsule) {
    int epic = 0;
    int legendary = 0;
    Candy *candy = dynamic_cast<Candy *>(capsule);
    Toy *toy = dynamic_cast<Toy *>(capsule);


    if (c_size != 10) {
        if (candy != NULL) {
            capsules[c_size] = new Candy(*candy);
            c_size++;
            return true;
        }
        capsules[c_size] = new Toy(*toy);
        c_size++;
        return true;
    }

    //In case the array is full:
    for (int i = 0; i < 10; i++) {
        if (capsules[i]->get_rarity() == Legendary)
            legendary++;
        if (capsules[i]->get_rarity() == Epic)
            epic++;
    }

    switch (capsule->get_rarity()) {
        case Common || Rare: {
            insert_extra(capsule);
            break;
        }
        case Legendary: {

            if (legendary == 0) {
                for (int i = 0; i < 10; i++) {
                    if (capsules[i]->get_rarity() == Common || capsules[i]->get_rarity() == Rare) {
                        delete capsules[i];//deleting existing capsule from arr
                        if (candy == NULL)
                            capsules[i] = new Toy(*toy);
                        else {
                            capsules[i] = new Candy(*candy);
                        }
                        legendary++;
                        break;
                    }
                }
            }
            insert_extra(capsule);
            break;
        }
        case Epic: {

            if (epic < 2) {
                for (int i = 0; i < 10; i++) {
                    if (capsules[i]->get_rarity() == Common || capsules[i]->get_rarity() == Rare) {
                        delete capsules[i];
                        if (candy == NULL)
                            capsules[i] = new Toy(*toy);
                        else {
                            capsules[i] = new Candy(*candy);
                        }
                        epic++;
                        break;
                    }
                }

            }
            insert_extra(capsule);

        }//end of Epic
    } //End of Switch
    if (legendary == 0) {
        cout << "|There are not enough legendary capsules in the " << Get_color();
        if (m_theme)
            cout << themes[m_theme] ;
        cout << " machine|\n";
    }
    if (epic < 2)
        cout << "|There are not enough epic capsules in the " << Get_color();
    if (m_theme)
        cout << themes[m_theme];
    cout << " machine|\n";
    return true;
}


void Gatcha_machine::print(ostream& out) {
    out << "Theme: " << themes[m_theme] << " Price: " << m_capsule_cost << "$";
}

ostream& operator << (ostream& out, Gatcha_machine& source) {
    source.print(out);
    return out;
}


Gatcha_machine::~Gatcha_machine() {

    if (c_size>0)
    {
         for (int i = 0; i < c_size; i++)
         {
             delete capsules[i];
         }
        
    }
    if (ec_size>0)
    {
        for (int i = 0; i <ec_size; i++)
        {
            delete Extra_capsules[i];
        }
        delete [] Extra_capsules;
    }
}