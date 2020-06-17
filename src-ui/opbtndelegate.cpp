#include "opbtndelegate.h"

#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#define FILE_OPERATE_COLUMN 3

OpBtnDelegate::OpBtnDelegate(Type _type, int _btnCol, QObject *parent) :
    QStyledItemDelegate(parent),
    type(_type),
    btnCol(_btnCol)
{
    if(type == Reader){
        btnCnt = 1;
        btnName << "del";
    }
    if(type == Book){
        btnCnt = 2;
        btnName << "add" << "del";
    }
    if(type == History){
        btnCnt = 2;
        btnName << "agr" << "ref";
    }
    if(type == Library){
        btnCnt = 2;
        btnName << "detail" << "borrow";
    }
    if(type == ReaderReq){
        btnCnt = 2;
        btnName << "detail" << "returnReq";
    }
    if(type == CancelReq){
        btnCnt = 1;
        btnName << "ref";
    }
    this->init();
}

void OpBtnDelegate::init(){
    Spacing = 5;
    Width = 25;
    Height = 20;
    mouseType = 1;
}

void OpBtnDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == btnCol){
        // 计算按钮显示区域
        int Half = (option.rect.width() - Width * btnCnt - Spacing * (btnCnt - 1)) / 2;
        int Top = (option.rect.height() - Height) / 2;

        for (int i=0;i<btnCnt;++i){
            // 绘制按钮
            QStyleOptionButton btn;
            btn.rect = QRect(option.rect.left() + Half + Width * i + Spacing * i,
                                option.rect.top() + Top, Width, Height);
            btn.state |= QStyle::State_Enabled;
            btn.iconSize = QSize(20, 20);
            btn.icon = btn.icon = QIcon(QPixmap(QString(":/image/%1%2").arg(btnName.at(i)).arg(1)));

            if(btn.rect.contains(mousePoint)){
                btn.icon = QIcon(QPixmap(QString(":/image/%1%2").arg(btnName.at(i)).arg(mouseType)));
            }
            QApplication::style()->drawControl(QStyle::CE_PushButton, &btn, painter);
        }
    }
    else QStyledItemDelegate::paint(painter, option, index);
}

bool OpBtnDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index){
    if (index.column() != btnCol)
        return false;

    mouseType = 1;
    bool bRepaint = false;
    QMouseEvent *pEvent = static_cast<QMouseEvent*> (event);
    mousePoint = pEvent->pos();

    int Half = (option.rect.width() - Width * btnCnt - Spacing * (btnCnt - 1)) / 2;
    int Top = (option.rect.height() - Height) / 2;

    // 还原鼠标样式
    QApplication::restoreOverrideCursor();

    for (int i=0;i<btnCnt;i++){
        QStyleOptionButton button;
        button.rect = QRect(option.rect.left() + Half + Width * i + Spacing * i,
                            option.rect.top() + Top, Width, Height);

        // 鼠标位于按钮之上
        if(!button.rect.contains(mousePoint)) continue;

        bRepaint = true;
        switch (event->type()){
            // 鼠标滑过
            case QEvent::MouseMove:{
                break;
            }
            // 鼠标按下
            case QEvent::MouseButtonPress:{
                mouseType = 2;
                break;
            }
            // 鼠标释放
            case QEvent::MouseButtonRelease:{
                if(type == Reader){
                    if(i == 0) emit del(index);
                }
                else if(type == Book){
                    if(i == 0) emit add(index);
                    else if(i == 1) emit del(index);
                }
                else if(type == History){
                    if(i == 0) emit agr(index);
                    else if(i == 1) emit ref(index);
                }
                else if(type == Library){
                    if(i == 0) emit detail(index);
                    //else if(i == 1) emit collect(index);
                    else if(i == 1) emit borrow(index);
                }
                else if(type == ReaderReq){
                    if(i == 0) emit detail(index);
                    else if(i == 1) emit ReturnReq(index);
                }
                else if(type == CancelReq){
                    if(i == 0) emit Cancel(index);
                }
                mouseType == 1;
                break;
            }
            default:break;
        }
    }

    return bRepaint;
}


