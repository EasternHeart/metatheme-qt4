#ifndef QMETATHEMESTYLE_H
#define QMETATHEMESTYLE_H

//#include <QWindowsStyle>
#include <QCleanlooksStyle>
#include <Qt3Support/Q3PtrDict>
#include <QFont>

extern "C"{
    #include <metathemeInt.h>
}

extern MT_TOOLKIT qt;

#define BaseStyle QCleanlooksStyle

class QMetaThemeStyle : public BaseStyle
{
    Q_OBJECT
public:
    explicit QMetaThemeStyle();

signals:
    
public slots:

public:
    void setColorPalette(MT_COLOR_PALETTE *pal);
    void setFont();

    QWidget *hoverWidget;
    int hoverPart;
    QWidget *toolButtonDropDownActiveWidget;
    void drawControl(ControlElement element,const QStyleOption *,
       QPainter *p,
       const QWidget *widget) const;
    QSize sizeFromContents ( ContentsType type, const QStyleOption * option, const QSize & contentsSize, const QWidget * widget = 0 ) const;


private:
   MT_ENGINE *mt_engine;
   QPalette qpalette;
   QFont qfont;
   bool qtonly;
   Q3PtrDict<QWidget> tabWidgets;

};

#endif // QMETATHEMESTYLE_H