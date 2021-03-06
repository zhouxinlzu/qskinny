/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_GRAPHIC_TEXTURE_FACTORY_H
#define QSK_GRAPHIC_TEXTURE_FACTORY_H

#include "QskGlobal.h"
#include "QskGraphic.h"
#include "QskColorFilter.h"
#include <QQuickTextureFactory>

class QskGraphic;

class QSK_EXPORT QskGraphicTextureFactory : public QQuickTextureFactory
{
public:
    enum RenderMode
    {
        Raster,
        OpenGL
    };

    QskGraphicTextureFactory();
    QskGraphicTextureFactory( const QskGraphic&, const QSize& size );

    virtual ~QskGraphicTextureFactory();

    void setGraphic( const QskGraphic& );
    QskGraphic graphic() const;

    void setColorFilter( const QskColorFilter& );
    const QskColorFilter& colorFilter() const;

    void setSize( const QSize& size );
    QSize size() const;

    virtual QSGTexture* createTexture( QQuickWindow* ) const override;
    virtual QSize textureSize() const override;
    virtual int textureByteCount() const override;

    virtual QImage image() const override;

    static uint createTexture(
        RenderMode, const QRect& rect, Qt::AspectRatioMode,
        const QskGraphic& , const QskColorFilter& );

private:
    QskGraphic m_graphic;
    QskColorFilter m_colorFilter;
    QSize m_size;
};

inline void QskGraphicTextureFactory::setGraphic( const QskGraphic& graphic )
{
    m_graphic = graphic;
}

inline QskGraphic QskGraphicTextureFactory::graphic() const
{
    return m_graphic;
}

inline void QskGraphicTextureFactory::setColorFilter(
    const QskColorFilter& colorFilter )
{
    m_colorFilter = colorFilter;
}

inline const QskColorFilter& QskGraphicTextureFactory::colorFilter() const
{
    return m_colorFilter;
}


inline void QskGraphicTextureFactory::setSize( const QSize& size )
{
    m_size = size;
}

inline QSize QskGraphicTextureFactory::size() const
{
    return m_size;
}

#endif
