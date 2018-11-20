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

#include "renamedialog.h"
#include "ui_renamedialog.h"


renameDialog::renameDialog(QFileInfo iFile,QWidget *parent):QDialog(parent),ui(new Ui::renameDialog)
{
    ui->setupUi(this);

    // set stylesheet from style.qrc
    setStyleSheet(CPrime::ThemeFunc::getStyleSheetFileContent(CPrime::StyleTypeName::DialogStyle));

    m_iFile = iFile;
    setWindowFlags(Qt::Dialog | Qt::Popup);
    setAttribute(Qt::WA_NativeWindow);
    setWindowTitle("Rename \"" + m_iFile.fileName() + "\"");
    ui->newName->setText(m_iFile.fileName());
    connect(ui->cancel, &QToolButton::clicked, this, &renameDialog::close);

    shotcuts();
}

renameDialog::~renameDialog()
{
    delete ui;
}

void renameDialog::shotcuts()
{
    QShortcut* shortcut;

    shortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    connect(shortcut, &QShortcut::activated, this, &renameDialog::on_done_clicked);
}

void renameDialog::on_done_clicked()
{
    if (ui->newName->text().count()) {
        if (QFile::rename(m_iFile.filePath(), m_iFile.path() + "/" + ui->newName->text())) {
            CPrime::InfoFunc::messageEngine("File Renamed Successfully.", CPrime::MessageType::Info,this);
            close();
        } else {
            CPrime::InfoFunc::messageEngine("File not Renamed.", CPrime::MessageType::Warning,this);
            close();
        }
    }
}

void renameDialog::on_newName_returnPressed()
{
    on_done_clicked();
}
