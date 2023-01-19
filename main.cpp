//
// Created by Ofek Eliyahu - 207753120 and Rony Zrihen - 318917549 .
//
#include "Player.h"

void sort_capsules_to_mchines(Gatcha_machine*machine,Capsule**capsule, int capsules_size);

int main() {

    Player user("ShitHead", 300);

    Gatcha_machine m_list[10] = { Gatcha_machine(None,"blue",33),Gatcha_machine(Dragon_ball_z,"rad",70),Gatcha_machine(Naruto,"green",15),Gatcha_machine(Pokemon,"green",20),Gatcha_machine(Attack_on_titan,"blue",55),Gatcha_machine(Bleach,"red",12),Gatcha_machine(SpyXFamily,"green",40),Gatcha_machine(Full_metal_alchemist,"blue",55),Gatcha_machine(None,"red",11),Gatcha_machine(None,"green",17) };


    Toy t1("lchigo kurosaki", Common,Bleach, "blue"), t2("loid forger",Rare,SpyXFamily, "red"), t3("Vegeta",Common,Dragon_ball_z, "green"),t4("Trunks",Epic,Dragon_ball_z, "green"),t5("Gohan",Epic,Dragon_ball_z, "green"),t6("goku",Legendary,Dragon_ball_z, "green"),t7("goku",Legendary,Dragon_ball_z, "green"), t8("naruto",Epic, Naruto, "blue"), t9("pikachu",Legendary,Pokemon , "red"), t10("eren yeager",Rare,Attack_on_titan, "green"), t11("edward elric", Epic,Full_metal_alchemist, "red");
    Candy c1("m&m",Epic, "chocolate", "blue"),c2("gummy",Common, "chocolate", "blue"),c3("lolipop",Rare, "chocolate", "blue"),c4("Pesek-zman",Common, "chocolate", "blue"),c5("m&m",Rare, "chocolate", "blue"),c6("Mekupelet",Common, "chocolate", "blue"),c7("m&m",Rare, "chocolate", "blue"),c8("Skittles",Rare, "sour", "blue"), c9("cane", Common, "sour", "blue"), c10("kinder",Common, "chocolate", "blue"), c11("cane", Rare, "sour", "blue");
    Capsule* list[22] = { &c1,&c2,&c3,&t1,&t2,&t3,&t4,&t5,&t6,&t7,&c4,&c5,&c6,&c7,&c8,&c9,&c10,&c11 ,&t8, &t9, &t10, &t11 };
    sort_capsules_to_mchines(m_list, list, 22);
    
    for (;;) {
        int choice;
        cout << "Gatcha Machines\n--------------\n";
        cout << "0. <Exit>\n";
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". <" << m_list[i] <<">" << endl;
        }
        cin >> choice;
        while (choice > 10 || choice < 0) {
            "No such machine\nTry again: ";
            cin >> choice;
        }
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
            if (t_temp != NULL&&machine[j].get_theme()==t_temp->Get_category()) {
                t_temp->calculate_rarity(machine[j].Get_cost());
                machine[j].insert_capsule(t_temp);
                flag++;
                break;
            }
            if (c_temp != NULL && machine[j].get_theme() == None && machine[j].Get_color() == c_temp->Get_color()) {
                c_temp->calculate_rarity(machine[j].Get_cost());
                machine[j].insert_capsule(c_temp);
                flag++;
                break;
            }
        }
        if (flag == 0) {
            for (int j = 0; j < 10; j++) {
                if (machine[j].get_theme() == None && machine[j].Get_color() == capsule[i]->Get_color()) {
                    capsule[i]->calculate_rarity(machine[j].Get_cost());
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