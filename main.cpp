//
// Created by Ofek Eliyahu and Rony Zrihen .
//
#include "Player.h"

void sort_capsules_to_mchines(Gatcha_machine*machine,Capsule**capsule, int capsules_size);

int main() {

    Player user("ShitHead", 1000);

    Gatcha_machine m_list[10] = { Gatcha_machine(None,"blue",100),Gatcha_machine(Dragon_ball_z,"rad",300),Gatcha_machine(Naruto,"green",150),Gatcha_machine(Pokemon,"green",200),Gatcha_machine(Attack_on_titan,"blue",125),Gatcha_machine(Bleach,"red",145),Gatcha_machine(SpyXFamily,"green",220),Gatcha_machine(Full_metal_alchemist,"blue",270),Gatcha_machine(None,"red",90),Gatcha_machine(None,"green",80) };


    Toy t1("lchigo kurosaki", Common,Bleach, "blue"), t2("loid forger",Rare,SpyXFamily, "red"), t3("goku",Legendary,Dragon_ball_z, "green"), t4("naruto",Epic, Naruto, "blue"), t5("pikachu",Legendary,Pokemon , "red"), t6("eren yeager",Rare,Attack_on_titan, "green"), t7("edward elric", Epic,Full_metal_alchemist, "red");
    Candy c1("m&m",Epic, "chocolate", "red"), c2("cane", Common, "sour", "blue"), c3("kinder",Legendary, "chocolate", "blue"), c4("cane", Common, "sour", "blue");
    Capsule* list[11] = { &c1,&c2,&c3,&t1,&t2,&t3,&t4,&t5,&t6,&t7,&c4 };
    sort_capsules_to_mchines(m_list, list, 11);
    
    for (;;) {
        int choice;
        cout << "Gatcha Machines\n--------------\n";
        cout << "0. <Exit>\n";
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". <" << m_list[i] <<">" << endl;
        }
        cin >> choice;

        if (!choice)
            return 0;

        user.Play_machine(m_list[choice - 1]);




    }
    

    return 0;
}


void sort_capsules_to_mchines(Gatcha_machine* machine, Capsule** capsule,int capsules_size) {

    for (int i = 0; i < capsules_size; i++)
    {
        Candy* c_temp = dynamic_cast<Candy*>(capsule[i]);
        Toy* t_temp = dynamic_cast<Toy*>(capsule[i]);
        int flag = 0;
        
       
        
        for (int j = 0; j < 10; j++) {
            if (t_temp != NULL&&machine[j].get_theme()==t_temp->get_Type()) {
                machine[j].insert_capsule(t_temp);
                flag++;
                break;
            }
            if (c_temp != NULL && machine[j].get_theme() == None && machine[j].Get_color() == c_temp->Get_color()) {
                machine[j].insert_capsule(c_temp);
                flag++;
                break;
            }
        }
        if (flag == 0) {
            for (int j = 0; j < 10; j++) {
                if (machine[j].get_theme() == None && machine[j].Get_color() == capsule[i]->Get_color()) {
                    machine[j].insert_capsule(capsule[i]);
                    flag++;
                    break;
                }
                  
            }
            if (flag == 0) {
                cout << "Couldn't find a machine for " << capsule[i]->Get_name() << endl;
            }
        }
    }
}