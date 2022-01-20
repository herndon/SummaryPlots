# crossSectionSummaryBarCharts

Summary plots:
Overall cross section summary bar chart
X + jets cross section summary bar chart

Adapted from CMS EXO long-lived summary plots.


It uses python 3.7 on osx with matplotlib.  The input is a csv file CrossSectionBarchartInputTable.csv.  The csv file is written with the root C scripts in SigmaSummary with exportBarChartFormat selected. It is possible to use a Apple Numbers spread sheet and convert it automatically by un-commenting the lines calling numbers2csv.scpt.  The entries in the csv or numbers file contain latex sequences (without using predefined latex macros). The script should be able to create sub-charts for individual topics as well using command line parameters.

(1) Overall cross section summary bar chart

the command which creates the bar chart is:
python3 makeCrossSectionBarChart.py -g -l ALL


(2) X + jets cross section summary bar chart

python3 makeCrossSectionBarChart.py -g -j -l EW DB TOP HIG

(3) Cross section ratio plot of measured cross section and predictions

python3 makeCrossSectionBarChart.py -g -r ALL