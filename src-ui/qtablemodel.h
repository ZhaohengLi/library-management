#ifndef QTABLEMODEL_H
#define QTABLEMODEL_H

#include <QAbstractTableModel>

class QTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum TableType {Reader, Book, History};

    explicit QTableModel(QObject *parent = 0);
    explicit QTableModel(TableType type, QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void setHorizontalHeader(const QStringList& headers);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void loadData(const QVector<QStringList>& data);
    QVector<QStringList>& DataVector() { return m_data; }
    ~QTableModel(void);


private:
    QStringList m_HorizontalHeader;
    QVector<QStringList> m_data;

};

#endif // QTABLEMODEL_H
