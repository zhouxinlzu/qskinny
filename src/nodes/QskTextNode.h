/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_TEXT_NODE_H
#define QSK_TEXT_NODE_H

#include "QskGlobal.h"
#include "QskNamespace.h"

#include <QSGTransformNode>
#include <QRectF>

class QskTextOptions;
class QskTextColors;
class QString;
class QFont;
class QQuickItem;

class QSK_EXPORT QskTextNode : public QSGTransformNode
{
public:
    QskTextNode();
    virtual ~QskTextNode();

    void setTextData( const QQuickItem* item,
        const QString& text, const QRectF&, const QFont&,
        const QskTextOptions&, const QskTextColors&,
        Qt::Alignment, Qsk::TextStyle );

#if 1
    // for the moment here TODO ...
    static QSizeF textSize( const QString&,
        const QFont&, const QskTextOptions& );
        
    static QSizeF textSize( const QString&, const QFont&,
        const QSizeF&, const QskTextOptions& );
#endif

private:
    QRectF m_rect;
    uint m_hash;
};

#endif
