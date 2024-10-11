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


# stairway plot (2024)

Modified the .csv file to include a proper label column (and some renaming of columns for clarity).

The same .csv file can be used for any configuration of cross sections in the plot, just needs to be extended.

The configuration to be shown in the plot is steered with the .yml files, provided here e.g. as `data_top_summary.yml`. This encodes the order, grouping and labels of the data, e.g.:
```
ttjets:
    data:
        ttbar_0j: $0j\ (p_{T} > 25\,GeV, |\eta| < 2.5)$
        ttbar_1j: $1j$
        ttbar_2j: $2j$
        ttbar_3j: $3j$
        ttbar_4j: ${\geq}4j$
        ttbb_13: ${\geq}2b\ (p_{T} > 20\,GeV, |\eta| < 2.4)$
        ttcc_13: ${\geq}2c\ (p_{T} > 20\,GeV, |\eta| < 2.4)$
    label: $t\overline{t}{+}jets$
```
will produce on group in the plot with the given label, consisting of the data entries (top to bottom), where each has a separate label.

The script can be used e.g. as
```
python3 make_xs_chart.py -i data_top_summary.csv -y data_top_summary.yml -o . --no-date
```
For labelling the plot the journal column of the .csv is printed next to the data point, and a hyperlink to the CMS public page is added (based on the cadi line number given).

Some standard plots

Horizontal global summary
python3 make_xs_chart.py --brokenaxis --horizontal --no-ratio --no-references --order-legend -d all -i data_all_summary.csv -y data_all_stack_summary.yml -o . --no-date

Horizontal smp sumary
python3 make_xs_chart.py --brokenaxis --horizontal --no-ratio --no-references --order-legend -d sm -i data_all_summary.csv -y data_sm_stack_summary.yml -o . --no-date


Horizontal top summary with ratios
python3 make_xs_chart.py --horizontal --rmax 2.0 --order-legend -d top -i data_all_summary.csv -y data_top_summary.yml -o . --no-date

Vertical summaries ew, ewjets, top, higgs
python3 make_xs_chart.py --order-legend -d ew -i data_all_summary.csv -y data_ew_summary.yml -o . --no-date

python3 make_xs_chart.py --order-legend -d ewjet -b 0.3 -i data_all_summary.csv -y data_ewjet_summary.yml -o . --no-date

python3 make_xs_chart.py --order-legend -d top -b 0.06 -i data_all_summary.csv -y data_top_summary.yml -o . --no-date


python3 make_xs_chart.py --order-legend -d higgs -i data_all_summary.csv -y data_higgs_summary.yml -o . --no-date


    
