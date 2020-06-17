#ifndef OPBTNDELEGATE_H
#define OPBTNDELEGATE_H

#include <QStyledItemDelegate>
#include <QPushButton>

class OpBtnDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    enum Type {Reader, Book, History, Library, ReaderReq, CancelReq};
    explicit OpBtnDelegate(Type _type, int _btnCol, QObject *parent = 0);
    void init();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    QPoint mousePoint;
    Type type;
    int btnCnt;
    int btnCol;
    QStringList btnName;
    int Spacing;  // 按钮之间的间距
    int Width;  // 按钮宽度
    int Height;  // 按钮高度
    int mouseType;  // 按钮状态 1.默认 2.点击
    bool collected; // 收藏状态 0.未收藏 1.已收藏

signals:
    void edit(const QModelIndex &index);
    void del(const QModelIndex &index);
    void add(const QModelIndex &index);
    void agr(const QModelIndex &index);
    void ref(const QModelIndex &index);
    void borrow(const QModelIndex &index);
    void detail(const QModelIndex &index);
    //void collect(const QModelIndex &index);
    void ReturnReq(const QModelIndex &index);
    void Cancel(const QModelIndex &index);

};

#endif // OPBTNDELEGATE_H
