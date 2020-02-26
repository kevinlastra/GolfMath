#include "fenprinc.h"
#include "fencodegen.h"

FenPrinc::FenPrinc()
{
    nom = new QLineEdit;
    classeMere = new QLineEdit;

    QFormLayout *definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", nom);
    definitionLayout->addRow("Classe &mère :", classeMere);

    QGroupBox *groupeDefinition = new QGroupBox("Définition de la classe");
    groupeDefinition->setLayout(definitionLayout);

    protections = new QCheckBox("Protéger le &header contre les inclusions mutltiples");
    protections->setChecked(true);
    genererConstructeur = new QCheckBox("Générer un &contrusteur par défault");
    genererDestructeur = new QCheckBox("Générer un &destructeur");

    QVBoxLayout *optionsLayout = new QVBoxLayout;
    optionsLayout->addWidget(protections);
    optionsLayout->addWidget(genererConstructeur);
    optionsLayout->addWidget(genererDestructeur);

    QGroupBox *groupeOptions = new QGroupBox("Options");
    groupeOptions->setLayout(optionsLayout);

    auteur = new QLineEdit;
    date = new QDateEdit;
    date->setDate(QDate::currentDate());
    role = new QTextEdit;

    QFormLayout *commentairesLayout = new QFormLayout;
    commentairesLayout->addRow("Auteur :", auteur);
    commentairesLayout->addRow("Da&te de création :", date);
    commentairesLayout->addRow("&Rôle de la classe :", role);

    groupeCommentaires = new QGroupBox("Ajouter des commentaires");
    groupeCommentaires->setCheckable(true);
    groupeCommentaires->setChecked(false);
    groupeCommentaires->setLayout(commentairesLayout);

    generer = new QPushButton("Générer code");
    quitter = new QPushButton("Quitter");

    QHBoxLayout *bouttonLayout = new QHBoxLayout;
    bouttonLayout->setAlignment(Qt::AlignRight);

    bouttonLayout->addWidget(generer);
    bouttonLayout->addWidget(quitter);

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupeDefinition);
    layoutPrincipal->addWidget(groupeOptions);
    layoutPrincipal->addWidget(groupeCommentaires);
    layoutPrincipal->addLayout(bouttonLayout);

    setLayout(layoutPrincipal);
    setWindowTitle("Class Generator");
    resize(400, 450);

    connect(generer, SIGNAL(clicked()), this, SLOT(genererCode()));
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void FenPrinc::genererCode(){
    if (nom->text().isEmpty()){
        QMessageBox::information(this, "Erreur", "Veuillez entrer au moins un nom de classe");
        return;
    }

    QString code;

    if (groupeCommentaires->isChecked()){
        code += "/*Auteur : " + auteur->text() + "\n";
        code += "Date de création : " + date->date().toString() + "\n\n";
        code += "Rôle :\n" + role->toPlainText() + "\n*/\n\n\n";
    }

    if (protections->isChecked()){
        code += "#ifndef HEADER_" + nom->text().toUpper() + "\n";
        code += "#define HEADER_" + nom->text().toUpper() + "\n\n\n";
    }

    code += "class " + nom->text();

    if (!classeMere->text().isEmpty()){
        code += " : public " + classeMere->text();
    }

    code += "\n{\n\n public:\n";
    if (genererConstructeur->isChecked()){
        code += "   " + nom->text() + "();\n";
    }
    if (genererDestructeur->isChecked()){
        code += "   ~" + nom->text() + "();\n";
    }

    code += "\n\n protected:\n";
    code += "\n\n private:\n\n\n";
    code += "};\n\n";

    if (protections->isChecked()){
        code += "#endif\n";
    }

    FenCodeGen *fenetreCode = new FenCodeGen(code, this);
    fenetreCode->exec();
}
