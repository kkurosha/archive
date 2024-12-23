from tkinter import *
import tkinter.ttk as ttk
import urllib.request
import xml.dom.minidom
import tkinter as tk
from tkinter import ttk
from datetime import datetime, timedelta
import matplotlib
import matplotlib.pyplot as plt

curr_data = datetime.today().date()

months_dict = {'Jan': 'Январь',
                'Feb': 'Февраль',
                'Mar': 'Март',
                'Apr': 'Апрель',
                'May': 'Май',
                'Jun': 'Июнь',
                'Jul': 'Июль',
                'Aug': 'Август',
                'Sep': 'Сентябрь',
                'Oct': 'Октябрь',
                'Nov': 'Ноябрь',
                'Dec': 'Декабрь'}

weeks = []
current_date_str = curr_data.strftime('%d.%m.%Y')
prev_date = curr_data - timedelta(weeks=1)
weeks.append(f"{prev_date.strftime('%d.%m.%Y')} - {current_date_str}")
for _ in range(3):
    new_date = prev_date - timedelta(weeks=1)
    weeks.append(f"{new_date.strftime('%d.%m.%Y')} - {(prev_date - timedelta(days=1)).strftime('%d.%m.%Y')}")
    prev_date = new_date

months = []
current_date_str = curr_data.strftime('%b %Y')
prev_date = curr_data
month_abbr, year = prev_date.strftime('%b %Y').split()
month_name = months_dict.get(month_abbr)
if month_name:
    months.append(f'{month_name} {year}')
for _ in range(3):
    prev_date -= timedelta(weeks=5)
    month_abbr, year = prev_date.strftime('%b %Y').split()
    month_name = months_dict.get(month_abbr)
    if month_name:
        months.append(f'{month_name} {year}')

kvartals = []
current_date_str = curr_data.strftime('%d.%m.%Y')
prev_date = curr_data - timedelta(weeks=12)
kvartals.append(f"{prev_date.strftime('%d.%m.%Y')} - {current_date_str}")
for _ in range(3):
    new_date = prev_date
    prev_date -= timedelta(weeks=12)
    kvartals.append(f"{prev_date.strftime('%d.%m.%Y')} - {new_date.strftime('%d.%m.%Y')}")

years = []
current_date = curr_data
years.append(current_date.strftime('%Y'))
for _ in range(3):
    current_date -= timedelta(weeks=52)
    years.append(current_date.strftime('%Y'))

def period_combo():
    choice = radio_state.get()
    if choice == 1:
        combo_period_tab2.config(values=weeks)
    elif choice == 2:
        combo_period_tab2.config(values=months)
    elif choice == 3:
        combo_period_tab2.config(values=kvartals)
    elif choice == 4:
        combo_period_tab2.config(values=years)
    combo_period_tab2.current(0)
    combo_period_tab2.grid(column=2, row=choice, padx=15, pady=5)

def click():
    amount = float(txt_input.get())
    first_currency = combo1.get()
    second_currency = combo2.get()
    first_value = curr_valute[curr_keys.index(first_currency)]
    second_value = curr_valute[curr_keys.index(second_currency)]
    converted_value = amount * first_value / second_value
    label_output.config(text=converted_value)

compar_with_month = { "Январь": 1, "Февраль": 2, "Март": 3,
                    "Апрель": 4, "Май": 5, "Июнь": 6,
                    "Июль": 7, "Август": 8, "Сентябрь": 9,
                    "Октябрь": 10, "Ноябрь": 11, "Декабрь": 12,
                    1: "янв", 2: "фев", 3: "март",
                    4: "апр", 5: "май", 6: "июнь",
                    7: "июль", 8: "авг", 9: "сен",
                    10: "окт", 11: "ноя", 12: "дек"}

def plot():
    period_choice = radio_state.get()
    dates = []
    points = []
    currency = combo_valute_tab2.get()
    if period_choice == 1:
        start_date = datetime.strptime(combo_period_tab2.get().split()[0], '%d.%m.%Y')
        for _ in range(7):
            dates.append(start_date.strftime('%d'))
            url = f"http://www.cbr.ru/scripts/XML_daily.asp?date_req={start_date.strftime('%d/%m/%Y')}"
            points.append(select(url)[currency])
            start_date += timedelta(days=1)
    elif period_choice == 2:
        month, year = combo_period_tab2.get().split()
        first_date = datetime(year=int(year), month=compar_with_month[month], day=1)
        day = 1
        month_num = compar_with_month[month]
        if month_num < 10:
            month_str = f'0{month_num}'
        else:
            month_str = str(month_num)
        if month != curr_data.strftime('%b'):
            while first_date.strftime('%m') == month_str:
                dates.append(day)
                url = f"http://www.cbr.ru/scripts/XML_daily.asp?date_req={first_date.strftime('%d.%m.%Y')}"
                points.append(select(url)[currency])
                first_date += timedelta(days=1)
                day += 1
        else:
            while day != int(curr_data.strftime('%d')):
                dates.append(day)
                url = f"http://www.cbr.ru/scripts/XML_daily.asp?date_req={first_date.strftime('%d.%m.%Y')}"
                points.append(select(url)[currency])
                first_date += timedelta(days=1)
                day += 1
    elif period_choice == 3:
        start_date = datetime.strptime(combo_period_tab2.get().split()[0], '%d.%m.%Y')
        for _ in range(13):
            dates.append(start_date.strftime('%d.%m'))
            url = f"http://www.cbr.ru/scripts/XML_daily.asp?date_req={start_date.strftime('%d/%m/%Y')}"
            points.append(select(url)[currency])
            start_date += timedelta(weeks=1)
    elif period_choice == 4:
        year = combo_period_tab2.get()
        year_diff = int(year) - int(curr_data.strftime('%Y'))
        if year_diff == 0:
            month_count = int(curr_data.strftime('%m'))
        else:
            month_count = 12
        for i in range(month_count):
            dates.append(compar_with_month[i+1])
            if i < 9:
                url = f"http://www.cbr.ru/scripts/XML_daily.asp?date_req=01/0{i+1}/{year}"
            else:
                url = f"http://www.cbr.ru/scripts/XML_daily.asp?date_req=01/{i+1}/{year}"
            points.append(select(url)[currency])

    fig = plt.figure()
    canvas = matplotlib.backends.backend_tkagg.FigureCanvasTkAgg(fig, master=tab2)
    plot_widget = canvas.get_tk_widget()
    fig.clear()

    if period_choice != 3:
        plt.plot(dates, points, c="g")
        plt.grid()
    else:
        plt.tick_params(axis='x', labelrotation=55)
        plt.plot(dates, points, c="g")
        plt.tight_layout()
        plt.grid()
    plot_widget.grid(row=6, column=0, columnspan=5, padx=30, pady=5)

def select(url):
    response = urllib.request.urlopen(url)
    xml_string = response.read().decode('windows-1251')
    dom = xml.dom.minidom.parseString(xml_string)
    dom.normalize()
    valute_dict = {}
    for valute in dom.getElementsByTagName('Valute'):
        name = valute.getElementsByTagName('Name')[0].childNodes[0].nodeValue
        value = float(valute.getElementsByTagName('Value')[0].childNodes[0].nodeValue.replace(',', '.')) / int(
            valute.getElementsByTagName('Nominal')[0].childNodes[0].nodeValue)
        valute_dict[name] = value
    valute_dict["Российский рубль"] = 1.0
    return valute_dict

url = f"http://www.cbr.ru/scripts/XML_daily.asp?date_req={current_date.strftime('%d/%m/%Y')}"
initial_data = select(url)
curr_keys = list(initial_data.keys())
curr_valute = list(initial_data.values())

window = Tk()
window.title("Конвертер валют")  # название
window.geometry("700x700")  # размеры

tab_control = ttk.Notebook(window)  # виджет управления вкладками
tab1 = ttk.Frame(tab_control)  # виджет рамки (вкладка)
tab2 = ttk.Frame(tab_control)
tab_control.add(tab1, text="Калькулятор валют")
tab_control.add(tab2, text="Динамика курса")

combo1 = ttk.Combobox(tab1, state="readonly", values=curr_keys)
combo1.current(0)
combo1.grid(column=0, row=0, padx=15, pady=15)

combo2 = ttk.Combobox(tab1, state="readonly", values=curr_keys)
combo2.current(1)
combo2.grid(column=0, row=2, padx=15, pady=5)

txt_input = Entry(tab1)  # поле ввода
txt_input.focus()
txt_input.grid(column=5, row=0, padx=8, pady=15)

btn1 = tk.Button(tab1, text="Конвертировать", command=click, height=2, width=15)
btn1.grid(column=10, row=0, padx=8, pady=15)
label_output = tk.Label(tab1, text="")
label_output.grid(column=5, row=2, padx=8, pady=15)

label_valute = Label(tab2, text="Валюта")
label_valute.grid(column=0, row=0, padx=75, pady=5)
label_period = Label(tab2, text="Период")
label_period.grid(column=1, row=0, padx=25, pady=5)
label_choice_period = Label(tab2, text="Выбор периода")
label_choice_period.grid(column=2, row=0, padx=30, pady=5)

combo_valute_tab2 = ttk.Combobox(tab2, state="readonly", values=curr_keys)
combo_valute_tab2.current(0)
combo_valute_tab2.grid(column=0, row=1, padx=15, pady=5)

radio_state = IntVar()
radiobutton1 = Radiobutton(tab2, text="Неделя", value=1, variable=radio_state, command=period_combo).grid(column=1, row=1, padx=20, pady=5)
radiobutton2 = Radiobutton(tab2, text="Месяц", value=2, variable=radio_state, command=period_combo).grid(column=1, row=2, padx=20, pady=5)
radiobutton3 = Radiobutton(tab2, text="Квартал", value=3, variable=radio_state, command=period_combo).grid(column=1, row=3, padx=20, pady=5)
radiobutton4 = Radiobutton(tab2, text="Год", value=4, variable=radio_state, command=period_combo).grid(column=1, row=4, padx=20, pady=5)

combo_period_tab2 = ttk.Combobox(tab2, state="readonly")
combo_graph = ttk.Combobox(tab2, state="readonly")
btn2 = tk.Button(tab2, text="Построить график", command=plot, height=3, width=20)
btn2.grid(row=4, column=0)

tab_control.pack(expand=1, fill='both')
window.mainloop()