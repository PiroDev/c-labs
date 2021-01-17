# Interaction function

from functions import list_filter_full_squares, list_shift_left


def shift():
    try:
        data = list(map(int, shift_array_entry.get().split()))
        if len(data) <= 0:
            raise ValueError

        shift = int(shift_count_entry.get())
        if shift < 0:
            raise ValueError

        data = list_shift_left(data, shift)
        shift_array_entry.delete(0, "end")
        shift_array_entry.insert("end", " ".join(map(str, data)))
    except Exception:
        tkmb.showerror(
            "Error!",
            "Incorrect array or shift input.\nNote: shift must be >= 0, array separator is whitespace.",
        )


def filter():
    try:
        data = list(map(int, src_array_entry.get().split()))
        if len(data) <= 0:
            raise ValueError

        filtered = list_filter_full_squares(data)
        res_array_entry.config(state="normal")
        res_array_entry.delete(0, "end")
        res_array_entry.insert("end", " ".join(map(str, filtered)))
        res_array_entry.config(state="disabled")
    except Exception:
        tkmb.showerror(
            "Error!",
            "Incorrect array input.\nNote: array separator is whitespace.",
        )


# Tkinter GUI
import tkinter as tk
import tkinter.messagebox as tkmb

MAIN_COLOR = "#0B61A4"
SECOND_COLOR = "#66A3D2"
THIRD_COLOR = "#25567B"
FOURTH_COLOR = "#3F92D2"
TEXT_COLOR = "black"
FONT = "Calibri 18"

window = tk.Tk()
window.title("Example C library using in Python script")
window.geometry("580x390")
window.config(bg=MAIN_COLOR)

# Shift frames

frame_shift = tk.LabelFrame(
    window, text="Array shift", bg=MAIN_COLOR, fg=TEXT_COLOR, font="Calibri 14"
)

frame_shift_top = tk.Frame(frame_shift, bg=MAIN_COLOR)
frame_shift_bottom = tk.Frame(frame_shift, bg=MAIN_COLOR)

shift_array_entry = tk.Entry(
    frame_shift_top,
    width=20,
    font=FONT,
    bg=SECOND_COLOR,
    fg=TEXT_COLOR,
    highlightcolor=THIRD_COLOR,
    highlightbackground=THIRD_COLOR,
)

shift_button = tk.Button(
    frame_shift_top,
    text="Shift",
    font=FONT,
    bg=SECOND_COLOR,
    fg=TEXT_COLOR,
    activebackground=FOURTH_COLOR,
    activeforeground=TEXT_COLOR,
    command=lambda: shift(),
)

shift_array_entry.pack(side=tk.LEFT, padx=5, pady=5)
shift_button.pack(side=tk.LEFT, padx=5, pady=5)

frame_shift_top.pack(anchor="w")

shift_label = tk.Label(
    frame_shift_bottom,
    text="To the left by: ",
    font="Calibri 16",
    bg=MAIN_COLOR,
    fg=TEXT_COLOR,
    borderwidth=0,
)

shift_count_entry = tk.Entry(
    frame_shift_bottom,
    width=3,
    font=FONT,
    bg=SECOND_COLOR,
    fg=TEXT_COLOR,
    highlightcolor=THIRD_COLOR,
    highlightbackground=THIRD_COLOR,
)

shift_label.pack(side=tk.LEFT, padx=5, pady=5)
shift_count_entry.pack(side=tk.LEFT, padx=5, pady=5)

frame_shift_bottom.pack(anchor="w")

frame_shift.pack(anchor="w", padx=20, pady=20)

# Filter frames

frame_filter = tk.LabelFrame(
    window,
    text="Array filter full squares",
    bg=MAIN_COLOR,
    fg=TEXT_COLOR,
    font="Calibri 14",
)

frame_filter_top = tk.Frame(frame_filter, bg=MAIN_COLOR)
frame_filter_bottom = tk.Frame(frame_filter, bg=MAIN_COLOR)

src_array_entry = tk.Entry(
    frame_filter_top,
    width=20,
    font=FONT,
    bg=SECOND_COLOR,
    fg=TEXT_COLOR,
    highlightcolor=THIRD_COLOR,
    highlightbackground=THIRD_COLOR,
)

filter_button = tk.Button(
    frame_filter_top,
    text="Filter",
    font=FONT,
    bg=SECOND_COLOR,
    fg=TEXT_COLOR,
    activebackground=FOURTH_COLOR,
    activeforeground=TEXT_COLOR,
    command=lambda: filter(),
)

src_array_entry.pack(side=tk.LEFT, padx=5, pady=5)
filter_button.pack(side=tk.LEFT, padx=5, pady=5)

res_array_entry = tk.Entry(
    frame_filter_bottom,
    state="disabled",
    width=20,
    font=FONT,
    disabledbackground=SECOND_COLOR,
    disabledforeground=TEXT_COLOR,
)

res_array_entry.pack(side=tk.LEFT, padx=5, pady=5)

frame_filter_top.pack(anchor="w")
frame_filter_bottom.pack(anchor="w")

frame_filter.pack(anchor="w", padx=20, pady=20)

window.mainloop()
