#include "qtablemodel.h"

QTableModel::QTableModel(QObject *parent) :
    QAbstractTableModel(parent){
}

QTableModel::QTableModel(TableType type, QObject *parent) :
    QAbstractTableModel(parent){
    if(type == Reader){
        this->setHorizontalHeader(QStringList() << "读者id" << "读者姓名" << "借阅数量" << "操作");
    }
    else if(type == Book){
        this->setHorizontalHeader(QStringList() << "书籍id" << "书籍名称" << "作者" << "出版社" << "在馆数量" << "借出数量" << "操作");
    }
    else if(type == History){
        this->setHorizontalHeader(QStringList() << "历史记录id" << "读者id" << "读者姓名" << "书籍id" << "书籍名称" << "借书时间" << "还书时间" << "借阅状态" << "操作");
    }
}

QTableModel::~QTableModel() {}

int QTableModel::rowCount(const QModelIndex &parent) const {
    return m_data.size();
}
int QTableModel::columnCount(const QModelIndex &parent) const {
    return m_HorizontalHeader.count();
}
QVariant QTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole) {
        int ncol = index.column();
        int nrow =  index.row();
        QStringList values = m_data.at(nrow);
        if (values.size() > ncol) return values.at(ncol);
        else return QVariant();
    }
    return QVariant();
}
Qt::ItemFlags QTableModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) return Qt::NoItemFlags;

    Qt::ItemFlags flag = QAbstractItemModel::flags(index);

    flag|=Qt::ItemIsEditable; // 设置单元格可编辑,此处注释,单元格无法被编辑
    return flag;
}
void QTableModel::setHorizontalHeader(const QStringList &headers) {
    m_HorizontalHeader = headers;
}
QVariant QTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        return m_HorizontalHeader.at(section);
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}
void QTableModel::loadData(const QVector<QStringList> &data) {
    m_data = data;
}
