/***************************************************************************
 *   Copyright (C) 2018 by santiago González                               *
 *   santigoro@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#ifndef VOLTREG_H
#define VOLTREG_H

#include "e-volt_reg.h"
#include "itemlibrary.h"

#include <QObject>


class  VoltReg : public Component, public eVoltReg
{
    Q_OBJECT
    Q_PROPERTY( double Volts READ vRef  WRITE setVRef DESIGNABLE true USER true )
    
    public:

        VoltReg( QObject* parent, QString type, QString id );
        ~VoltReg();
        
 static Component* construct( QObject* parent, QString type, QString id );
 static LibraryItem *libraryItem();
        
        virtual void setVRef( double vref );

        virtual void paint( QPainter* p, const QStyleOptionGraphicsItem* option, QWidget* widget );
};


#endif
