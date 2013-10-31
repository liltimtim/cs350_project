<h1>CSCE 350 Project</h1>
<p>
Facial Expression Recognision<Br/>
Authors: Richard Abercrombie, Tim Barrett
</p>
<h2>Notes</h2>

<h4>Dependancies:</h4>
<ol>
    <li>Boost Library 
        <ul>
            <li>Follow this <a href='http://particlephysicsandcode.wordpress.com/2013/03/11/installing-boost-1-52-ubuntu-12-04-fedora/'>tutorial</a></li>
            <li>Also run <code>sudo apt-get install libz-dev</code></li>
        </ul>
    </li>
</ol>

<h4>Compiling and Running</h4>
<p>
    <code>g++ -I ./boost_1_54_0 main.cpp -L./boost_1_54_0/stage/lib/ -lboost_system -lboost_filesystem</code> <br/>
    <code>LD_LIBRARY_PATH="./boost_1_54_0/stage/lib/" ./a.out </code>
</p>

<h2>To Do</h2>


