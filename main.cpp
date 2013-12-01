/****************************************************************
 * Main program for parsing text for frequency counts and index.
 *
 * Author/copyright:  Richard Abercrombie and Timothy Barrett
 * Date: 1 December 2013
 *
**/
#include "Main.h"
#include <dirent.h>
static const char TAG[] = "Main: ";

int main(int argc, char *argv[])
{
  string timeCallOutput;
  string dataFileName;
  string stopWordsFileName;
  string outFileName;
  string logFileName;
  ofstream outStream;
  Scanner dataFile;
  Scanner stopWordsFile;

  Utils::CheckArgs(4, argc, argv, "stoplistfilename datafilename outfilename logfilename");
  stopWordsFileName = (string) argv[1];
  dataFileName = (string) argv[2];
  outFileName = (string) argv[3];
  logFileName = (string) argv[4];

  Utils::LogFileOpen(logFileName);
  Utils::FileOpen(outStream, outFileName);

  Utils::logStream << TAG << "Beginning execution" << endl;
  timeCallOutput = Utils::timecall("beginning");
  Utils::logStream << timeCallOutput;
  Utils::logStream.flush();

  Utils::logStream << TAG << "stoplistfile  '" << stopWordsFileName << "'" << endl;
  Utils::logStream << TAG << "datafile '" << dataFileName << "'" << endl;
  Utils::logStream << TAG << "outfile  '" << outFileName << "'" << endl;

  // dataFile.openFile(dataFileName);
  // document = parser.readText(stopWords, dataFile);
  // dataFile.close();

  // outStream << TAG << "SINGLE TERMS\n" << document.singleTerms() << endl;
  // outStream.flush();

  // outStream << TAG << "BIGRAMS\n" << document.bigrams() << endl;
  // outStream.flush();

  Utils::FileClose(outStream);

  Utils::logStream << TAG << "Ending execution" << endl;
  timeCallOutput = Utils::timecall("ending");
  Utils::logStream << timeCallOutput;
  Utils::logStream.flush();

  return 0;
}
