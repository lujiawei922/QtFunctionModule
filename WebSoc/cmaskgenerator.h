/*!
 * \file cmaskgenerator.h
 * \brief Short description
 * Detailed description
 * of my file.
 * \date  2019-09-03
 * \author ljw <ljw@lierda.com>
 */
#ifndef CMASKGENERATOR_H
#define CMASKGENERATOR_H

#include <QMaskGenerator>
class CMaskGenerator : public QMaskGenerator
{
    Q_DISABLE_COPY(CMaskGenerator)
public:
    CMaskGenerator();
    virtual quint32 nextMask();
    virtual bool seed();
};

#endif // CMASKGENERATOR_H
