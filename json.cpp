#include "json.h"
JObject::JObject()
{
}
int JObject::Init(const QJsonObject &obj)
{
    m_obj = obj;
    return 0;
}
int JObject::Init(const QString &str)
{
    QByteArray byte_array = str.toUtf8();
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isObject())
        {
            m_obj = parse_doucment.object();
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -2;
    }
    return 0;
}
int JObject::Init(const QByteArray &byte_array)
{
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isObject())
        {
            m_obj = parse_doucment.object();
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -2;
    }
    return 0;
}
int JObject::GetStringValue(const QString &key,QString &value)
{
    if(m_obj.contains(key))
    {
        QJsonValue name_value = m_obj.value(key);
        if(name_value.isString())
        {
            value = name_value.toString();
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}
int JObject::GetDoubleValue(const QString &key,double &value)
{
    if(m_obj.contains(key))
    {
        QJsonValue name_value = m_obj.value(key);
        if(name_value.isDouble())
        {
            value = name_value.toDouble();
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}
int JObject::GetArrayValue(const QString &key,JArray &value)
{
    if(m_obj.contains(key))
    {
        QJsonValue name_value = m_obj.value(key);
        if(name_value.isArray())
        {
            value.Init(name_value.toArray());
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}
int JObject::GetObjectValue(const QString &key,JObject &value)
{
    if(m_obj.contains(key))
    {
        QJsonValue name_value = m_obj.value(key);
        if(name_value.isObject())
        {
            value.Init(name_value.toObject());
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}
QJsonObject JObject::ToQJsonObject()
{
	return m_obj;
}
QStringList JObject::Keys()
{
    return m_obj.keys();
}

int JArray::Init(const QJsonArray &array)
{
    m_array = array;
    return 0;
}
int JArray::Init(const QString &str)
{
    QByteArray byte_array = str.toUtf8();
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isArray())
        {
            m_array = parse_doucment.array();
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -2;
    }
    return 0;
}
int JArray::Init(const QByteArray &byte_array)
{
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isArray())
        {
            m_array = parse_doucment.array();
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -2;
    }
    return 0;
}
int JArray::GetStringValue(const int &i,QString &value)
{
    if(i > m_array.size() || i < 0)
    {
        return -1;
    }
    QJsonValue name_value = m_array.at(i);
    if(name_value.isString())
    {
        value = name_value.toString();
    }
    else
    {
        return -2;
    }
    return 0;
}
int JArray::GetDoubleValue(const int &i,double &value)
{
    if(i > m_array.size() || i<m_array.size())
    {
        return -1;
    }
    QJsonValue name_value = m_array.at(i);
    if(name_value.isString())
    {
        value = name_value.toDouble();
    }
    else
    {
        return -2;
    }
    return 0;
}
int JArray::GetObjectValue(const int &i,JObject &value)
{
    if(i > m_array.size() || i< 0)
    {
        qDebug()<<"size:"<<m_array.size();
        return -1;
    }
    QJsonValue name_value = m_array.at(i);
    if(name_value.isObject())
    {
        value.Init(name_value.toObject());
    }
    else
    {
        return -2;
    }
    return 0;
}
int JArray::ToStringList(QStringList &list)
{
    for(int i=0;i<m_array.size();i++)
    {
        QString value;
        if(GetStringValue(i,value))
        {
            return -1;
        }
        list.append(value);
    }
    return 0;
}
int JArray::Size()
{
    return m_array.size();
}
