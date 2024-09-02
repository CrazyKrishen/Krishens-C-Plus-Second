
[ . . . . ]
void recurseAddDir(QDir d, bool recursive=true, bool symlinks=false )

{
 d.setSorting( QDir::Name );

QDir::Filters df = QDir::Files | QDir::NoDotAndDotDot;

if (recursive) df |= QDir::Dirs;

if (not symlinks) df |= QDir::NoSymLinks;

QStringList qsl = d.entryList(df, QDir::Name | QDir::DirsFirst);

foreach (const QString &entry, qsl) {
  QFileInfo finfo(d, entry);

  if ( finfo.isDir() )
  {
  QDir sd(finfo.absoluteFilePath());
  recurseAddDir(sd);
  }

  else
  {
  if (finfo.completeSuffix()=="mp3")
  addMp3File(finfo.absoluteFilePath()); 1
  }
  }
 }
 [ . . . . ]



A directory , sometimes called a folder , is a container for files. Because a directory can
also contain other directories, it has a natural tree structure.
A directory can also contain symbolic links (called symlinks ) that point to other files or directories. A symlink
is a reference that can be used instead of the name or path for most operations that
handle files or directories.
The classes QDir and QFileInfo enable you to obtain a list of the contents of a directory and
then get information about each entry.
Above shows a recursive function that uses these classes to visit selected items in a directory.


 The first parameter identifies the directory that is to be traversed.

 The second parameter determines whether the function should recursively descend
 into any subdirectories that it finds in the directory

 The third parameter determines
whether the function should process the symlinks that it finds in the director






The application listed in Example 4.3 reuses QDirIterator to accomplish the same
thing with fewer lines of code.

int main (int argc, char* argv[])
{
 QCoreApplication app(argc, argv);
 QDir dir = QDir::current();
 if (app.arguments().size() > 1) {
 dir = app.arguments()[1];
 }
 if (!dir.exists()) {
 cerr << dir.path() << " does not exist!" << endl;
 usage();
 return -1;
 }
 QDirIterator qdi(dir.absolutePath(),
 QStringList() << "*.mp3",
 QDir::NoSymLinks | QDir::Files,
 QDirIterator::Subdirectories );
 while (qdi.hasNext()) {
 addMp3File(qdi.next());
 }





 There is an important difference between the two applications. In Example 4.2 , the
 call to the project-specific function, addMp3File() , occurs inside the definition of the
 function, recurseAddDir() , that manages the iteration, severely limiting the reusability of that function. In Example 4.3 , QDirIterator manages the iteration. The call to
 addMp3File() occurs in the client code for QDirIterator ( main() ) and, thus, can have
 no effect on the reusability of that class. Using the iterator pattern in appropriate places
 can make your code much simpler and easier to reuse
