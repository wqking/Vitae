#ifndef DASHBOARDWIDGET_H
#define DASHBOARDWIDGET_H

#include "qt/vitae/furabstractlistitemdelegate.h"
#include "qt/vitae/furlistrow.h"
#include "transactiontablemodel.h"
#include "qt/vitae/txrow.h"

#include <QWidget>

/*
#include <QBarCategoryAxis>
#include <QBarSet>
#include <QChart>
#include <QValueAxis>

 QT_CHARTS_USE_NAMESPACE
 */

class VITAEGUI;
class WalletModel;

namespace Ui {
class DashboardWidget;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class DashboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardWidget(VITAEGUI* _window, QWidget *parent = nullptr);
    ~DashboardWidget();

    void setWalletModel(WalletModel *model);
    void loadChart();
private slots:
    void handleTransactionClicked(const QModelIndex &index);

    void changeTheme(bool isLightTheme, QString &theme);
    void changeChartColors();
private:
    Ui::DashboardWidget *ui;
    VITAEGUI* window;
    // Painter delegate
    FurAbstractListItemDelegate* txViewDelegate;
    // Model
    TransactionTableModel* txModel;

    /*
    // Chart
    QBarSet *set0;
    QBarSet *set1;

    QBarCategoryAxis *axisX;
    QValueAxis *axisY;

    QChart *chart;
     */
};

#endif // DASHBOARDWIDGET_H
