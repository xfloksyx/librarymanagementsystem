# librarymanagementsystem
Library Management System
This is a C++ program written by Marouane El Hizabri for a library management system. It allows users to add and remove books from the library, as well as check out and return books. The program also keeps track of which books are currently checked out and by whom.

The program is divided into three main classes: Livre, Utilisateur, and Bibliotheque.

The Livre class represents a book in the library. It has four attributes:

Titre: The title of the book
Auteur: The author of the book
ISBN: The ISBN number of the book
Status_emprunt: A boolean value indicating whether the book is currently checked out
The Utilisateur class represents a user of the library. It has three attributes:

Nom: The user's name
Prenom: The user's first name
ID: The user's ID number
The Bibliotheque class represents the library itself. It has two attributes:

Nom: The name of the library
LivresDispo: A vector of all the books in the library
The program works by first creating instances of the Livre, Utilisateur, and Bibliotheque classes. Then, the user can interact with the library by calling methods on these objects.

For example, to add a book to the library, the user would call the ajouterLivreBiblio() method on the Bibliotheque object. To check out a book, the user would call the emprunterLivre() method on the Utilisateur object. And to return a book, the user would call the rendreLivre() method on the Utilisateur object.

The program also includes a number of helper functions, such as AfficherLivre(), which displays the information about a book, and AfficherUtilisateur(), which displays the information about a user.

This program is a good example of how object-oriented programming can be used to create a complex application. By dividing the program into classes, it is easier to understand and maintain the code. Additionally, by using objects, it is easier to reuse code in other applications.
