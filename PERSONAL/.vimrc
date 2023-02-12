
source $VIMRUNTIME/defaults.vim

set incsearch
set nocompatible
filetype on
filetype plugin on
filetype indent on
syntax on
set number
set relativenumber
set cursorline

set shiftwidth=5
set tabstop=5
set nobackup
set ignorecase
set smartcase
set showcmd
set showmode
set showmatch
set hlsearch

set nowrap

set wildmenu
set wildmode=list:longest
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx

let NERDTreeQuitOnOpen = 1
let NERDTreeMinimalUI = 1
let NERDTreeDirArrows = 1

let g:user42 = 'mguerga'
let g:mail42 = 'mguerga@42lausanne.ch'

let g:NERDTreeGitStatusIdicatorMapCustom = {
			\ 'Modified'	:'✹',
			\ 'Staged'	:'✚',
			\ 'Untracked'	:'✭',
			\ 'Renamed'	:'➜',
			\ 'Unmerged'	:'═',
			\ 'Deleted'	:'✖',
			\ 'Dirty'		:'✗',
			\ 'Ignored'	:'☒',
			\ 'Clean'		:'✔︎',
			\ 'Unknown'	:'?',
			\ }

" PLUGINS ----------------------------------------------------------{{{
call plug#begin('~/.vim/plugged')
	Plug 'preservim/nerdtree' |
		  \ Plug 'Xuyuanp/nerdtree-git-plugin'
	Plug 'xbeheydt/42-vim-stdheader'
	Plug 'ggVGc/vim-fuzzysearch'

call plug#end()
" Plugin code goes here.

" }}}

" MAPPINGS ---------------------------------------------------------{{{
inoremap hh <esc>
let mapleader = "\\"
nnoremap <leader>\ ``
nnoremap <space> :
nnoremap zz :w<CR>

nnoremap o o<esc>
nnoremap O O<esc>
nnoremap <c-z> <nop>
nnoremap <c-j> <c-w>j
nnoremap <c-k> <c-w>k
nnoremap <c-h> <c-w>h
nnoremap <c-l> <c-w>l
nnoremap <F1> :NERDTreeToggle<cr>
nnoremap <F2> :NERDTreeFind<cr>
let NERDTreeIgnore =['\.git$', '\.jpg$', '\.mp4$', '\.ogg$', '\.iso$', '\.pdf$', '\.pyc$', '\.odt$', '\.png$', '\.gif$', '\,db$']

" Mappings code goes here. 
"
" }}}

" VIMSCRIPT --------------------------------------------------------{{{
"
" This will enable code folding.
" Use the marker method of folding.
augroup filetype_vim
	autocmd!
	autocmd FileType vim setlocal foldmethod=marker
augroup END

if version >= 703
	set undodir=~/.vim/backup
	set undofile
	set undoreload=10000
endif

"	start nerdtree when vim is started without file arguments.
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif

"	Automatically close a tab if the only remaining window is NerdTree.
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | endif
	
augroup cursor_off
	autocmd!
	autocmd WinLeave * set nocursorline nocursorcolumn
	autocmd WinEnter * set  cursorline cursorcolumn
augroup END
" More Vimscripts code goes here.

" }}}

" STATUS LINE --------------------------------------------------------{{{

"Status bar code goes here.

" }}}


