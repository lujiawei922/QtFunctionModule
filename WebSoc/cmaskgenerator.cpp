/*!
 * \file cmaskgenerator.cpp
 * \brief Short description
 * Detailed description
 * of my file.
 * \date  2019-09-03
 * \author ljw <ljw@lierda.com>
 */
#include "cmaskgenerator.h"
#include <QDateTime>
CMaskGenerator::CMaskGenerator()
{

}

quint32 CMaskGenerator::nextMask()
{
    quint32 val = quint32((double(qrand()) / RAND_MAX) * std::numeric_limits<quint32>::max());
    while (val == 0)
    {
    seed();
    val = quint32((double(qrand()) / RAND_MAX) * std::numeric_limits<quint32>::max());
    }
    return val;
}

bool CMaskGenerator::seed()
{
    qsrand(QDateTime::currentDateTime().toTime_t());
    return true;
}
