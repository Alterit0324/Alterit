#include <avz.h>

using namespace AvZ;

void Script()
{
    OpenMultipleEffective('Q', MAIN_UI_OR_FIGHT_UI);

    KeyConnect('T', [=]()
               {
        auto zombie = GetMainObject()->zombieArray();
        for (int index = 0; index < GetMainObject()->zombieTotal(); ++index) {
            if (zombie[index].isExist() && !zombie[index].isDead()) {
                zombie[index].abscissa() = zombie[index].abscissa() + 1;
            }
        } });

    KeyConnect('J', [=]()
               {
        auto zombie = GetMainObject()->zombieArray();
        for (int index = 0; index < GetMainObject()->zombieTotal(); ++index) {
            if (zombie[index].isExist() && !zombie[index].isDead()) {
                zombie[index].abscissa() = zombie[index].abscissa() - 1;
            }
        } });

    KeyConnect('S', [=]()
               {
        auto zombie = GetMainObject()->zombieArray();
        for (int index = 0; index < GetMainObject()->zombieTotal(); ++index) {
            if (zombie[index].isExist() && !zombie[index].isDead()) {
                ShowErrorNotInQueue("僵尸坐标为：#", zombie[index].abscissa());
            }
        } });
}