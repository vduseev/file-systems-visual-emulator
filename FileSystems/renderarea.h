#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QMap>
#include <QPixmap>
#include <QWidget>

#include "filesystem.h"

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path, Text, Pixmap };

    RenderArea( QWidget *parent = 0 );

signals:
	void blockSelected( long long );

public slots:
    void setPen( const QPen &pen );
    void setBrush( const QBrush &brush );

    void allowDrawing();
    void forbidDrawing();

    void setFileSystem( FileSystem* fileSystem );
    void setPage( int page );

protected:
    void paintEvent( QPaintEvent *event );
	void mousePressEvent( QMouseEvent* );

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    QPixmap pixmap;
    QMap<FileSystem::Block, QBrush> m_brushes;

    // control drawing area
    bool m_allowDrawing;

    // pointer to actual file system
    FileSystem* m_fileSystem;
    int m_page;

	QList<SIZE> m_selectedBlocks;
};

#endif // RENDERAREA_H
