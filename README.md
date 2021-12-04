# Pipex

A simple implementation that emulates the pipe functionality in terminal

## Functionality

For the first part only 1 pipe will be supported

For the bonus part multiple pipes and the "here document" functionality are implemented

## How to compile

### For the mandatory part
```
make
```

### For the bonus part
```
make bonus
```

## Usage
For the mandatory part
```
./pipex input_file cmd1 cmd2 output_file
```

For the bonus part
```
./pipex input_file cmd1 cmd2 ... cmdn output_file
```

```
./pipex here_doc delimiter cmd1 cmd2 ... cmdn output_file
```
