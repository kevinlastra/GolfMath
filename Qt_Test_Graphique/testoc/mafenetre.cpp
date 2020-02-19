#include "mafenetre.h"

MaFenetre::MaFenetre(int la, int lo) : QWidget()
{
    setFixedSize(la, lo);

    m_boutonDialogue = new QPushButton("Ouvrir boite de dialogue", this);
    m_boutonDialogue->move(180, 110);

    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
}

void MaFenetre::ouvrirDialogue()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    QMessageBox::information(this, "Fichier", "Vous voulez ouvrir :\n" + fichier);
}
