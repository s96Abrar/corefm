/*
CoreFM is a filemanager

CoreFM is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "progressdlg.h"

#include <QObject>
#include <QFileInfo>
#include <QDirIterator>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QMimeDatabase>
#include <QMimeType>
#include <QStorageInfo>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/vfs.h>
#include <QUrl>

#include <cprime/appopenfunc.h>
#include <cprime/desktopfile.h>


struct SizeAndCountText
{
    QString sizeText, countText, hiddenFileCount;
};

class ProgressWatcher;


class FileUtils {

public:
    static bool removeRecurse(const QString &path, const QString &name);
    static void recurseFolder(const QString &path, const QString &parent,QStringList *list);
    static qint64 totalSize(const QList<QUrl> &files);
    static QString getRealSuffix(const QString &name);
    static QIcon searchMimeIcon(QString mime,const QIcon &defaultIcon = QIcon::fromTheme("unknown"));

    static QString getFileFolderTree(const QString &path);
    static QString getMountPathByName(const QString displayName);
    static QString getFileSize(const QString &path);
    static QString getMultipleFileSize(const QStringList &paths);
    static QString getCountText(const QString path);
    static SizeAndCountText getF(const QStringList &paths);
    static qint64 getSize(const QString &path);
};

#endif // FILEUTILS_H
