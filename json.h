#ifndef JJSON_H
#define JJSON_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QObject>
#include <QDebug>
class JArray;
class JObject;

class JObject
{
private:
    QJsonObject m_obj;
public:
    JObject();
    int Init(const QJsonObject &obj);
    int Init(const QString &str);
    int Init(const QByteArray &byte_array);
    int GetStringValue(const QString &key,QString &value);
    int GetDoubleValue(const QString &key,double &value);
    int GetArrayValue(const QString &key,JArray &value);
    int GetObjectValue(const QString &key,JObject &value);
	QJsonObject ToQJsonObject();
	QStringList Keys();
};

class JArray
{
private:
    QJsonArray m_array;
public:
    int Init(const QJsonArray &array);
    int Init(const QString &str);
    int Init(const QByteArray &byte_array);
    int GetStringValue(const int &i,QString &value);
    int GetDoubleValue(const int &i,double &value);
    int GetObjectValue(const int &i, JObject &value);
    int ToStringList(QStringList &list);
    int Size();
};

#endif // JSON_H
