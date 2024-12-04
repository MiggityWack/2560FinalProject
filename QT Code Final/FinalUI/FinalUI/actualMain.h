#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class actualMain; }
QT_END_NAMESPACE

class actualMain : public actualMain
{
    Q_OBJECT

public:
    actualMain(QWidget *parent = nullptr);
    ~actualMain();
    float weeklyMileageNum = 0;
    int mondayMileage = 0;
    int tuesdayMileage = 0;
    int wednesdayMileage = 0;
    int thursdayMileage = 0;
    int fridayMileage = 0;
    int saturdayMileage = 0;
    int sundayMileage = 0;
    float mileagePercents[5][7] =
        {{0, 0.1, 0.2, 0.15, 0.15, 0.25, 0.15},
         {0.3, 0.25, 0.1, 0.1, 0.15, 0, 0.1},
         {0.15, 0.1, 0.4, 0, 0.2, 0.1, 0.05},
         {0.2, 0, 0.1, 0.25, 0.25, 0.2, 0},
         {0.15, 0, 0.15, 0.1, 0.2, 0.2, 0.2}};
    QString sprintWorkouts[10] =
        {"4x400m", "12x100m", "8x100m hill", "6x200m hill sprints",
         "10x55m", "8 30sec sprints", "5 20sec sprints", "4x200m hill"
         "8x100m", "6x150m"};
    QString distanceWorkouts[10] =
        {"8x400m", "4x800m", "6 hill loops", "25min tempo",
         "3 by 2x4x800m ladder", "2 mile tempo", "1000m then 400m repeats", "800m then 400m repeats"
         "3x1000m", "25min hill tempo"};

private slots:
    void on_runnerType_currentIndexChanged(int index);

    void on_update_clicked();

    void on_weeklyMileage_editingFinished();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
